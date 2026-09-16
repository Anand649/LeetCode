# Partition Labels

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 16, 2026 |
| **Tags** | Hash Table, Two Pointers, String, Greedy |
| **Link** | [View Problem](https://leetcode.com/problems/partition-labels/) |
| **Runtime** | 0 ms |
| **Memory** | 9.4 MB |

## Problem Description

<p>You are given a string <code>s</code>. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string <code>"ababcc"</code> can be partitioned into <code>["abab", "cc"]</code>, but partitions such as <code>["aba", "bcc"]</code> or <code>["ab", "ab", "cc"]</code> are invalid.</p>

<p>Note that the partition is done so that after concatenating all the parts in order, the resultant string should be <code>s</code>.</p>

<p>Return <em>a list of integers representing the size of these parts</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "ababcbacadefegdehijhklij"
<strong>Output:</strong> [9,7,8]
<strong>Explanation:</strong>
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "eccbbbbdec"
<strong>Output:</strong> [10]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: 2 solutions (explanation + picture) ^^
**Author**: [@andrii_khlevniuk](https://leetcode.com/andrii_khlevniuk/)
**Upvotes**: 84 👍
**Link**: [View Original Post](https://leetcode.com/problems/partition-labels/solutions/899214/)

---

Both solutions are two-pass, `O(N)` time, `O(N)` space.

**Explanation**

A key fact to understand is that each character has its "range" (drawn as colored bar on the picture). The range is defined by the lowest index of the character in the input string and its highest index. 
<br>
![image](https://assets.leetcode.com/users/images/355b2c53-8f89-4fab-9a08-a77e9d0f5e92_1602977187.033552.png)
<br>
We are searching for the intervals `(j, i]` so that "ranges" of all characters in this interval lie inside it.
Note that for the task we actually need only the endpoints of the "ranges" (you don\'t need startpoints).
<br>
![image](https://assets.leetcode.com/users/images/4b3adda7-dda2-4849-97f7-d7ccd89bb4d5_1602977658.9728687.png)
<br>
We hit new partition checkpoint at index `i` iff the enpoints of all characters after the previous partition checkpoint are less than or equal than `i`.
In other words we hit a new partition checkpoint  precisely when the running **maximum** enpoint is equal to `i`.
For example, this is **not** checkpoint situation:
<br>
![image](https://assets.leetcode.com/users/images/a3fac751-61fe-43bb-a93a-186ca32d86e4_1602981474.6688743.png)
<br>
The algo is the following:
* at the first pass use `map M` to store the endpoints of ranges for all characters in a string;
* at the second pass use running maximum `MM` to store the largest enpoint of the characters in the current partition segment. Let `j` be the previous partition checkpoint and `i` be the current index. As soon as `MM` equals current index `i` we hit the new partition checkpoint: `push_back` `j-i` into the output vector, set `j` to `i` and proceed.

**Solution 1**

```
vector<int> partitionLabels(string s)
{
	 int M[256]{0};   
	 vector<int> out;

	 for(int i{0}; i<size(s); ++i) M[s[i]]=i;

	 for(int i{0}, j{-1}, MM{0}; i<size(s); ++i)
		 if((MM = max(MM, M[s[i]]))==i)
			 out.push_back(i-j), j=i; 

	 return out;
}
```

**Solution 2**

This solution is worse, instead of using the running endpoint maximum it uses `unordered_set` to store the chars with enpoints larger than the current index `i`.
We hit the partition checkpoint as soon as the set becomes empty.

```
vector<int> partitionLabels(string s)
{
	 int m[256]{0};   
	 vector<int> out;
	 unordered_set<char> us;

	 for(auto i{0}; i<size(s); ++i) m[s[i]]=i;

	 for(auto i{0}, j{-1}; i<size(s); ++i)
		 if(m[s[i]]==i)
			 if(us.erase(s[i]); empty(us))
				 out.push_back(i-j), j=i; 
			 else;               
		 else
			 us.insert(s[i]);

	 return out;
}
```

</details>
