# Subarray Sum Equals K

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 6, 2026 |
| **Tags** | Array, Hash Table, Prefix Sum |
| **Link** | [View Problem](https://leetcode.com/problems/subarray-sum-equals-k/) |
| **Runtime** | 68 ms |
| **Memory** | 47.7 MB |

## Problem Description

<p>Given an array of integers <code>nums</code> and an integer <code>k</code>, return <em>the total number of subarrays whose sum equals to</em> <code>k</code>.</p>

<p>A subarray is a contiguous <strong>non-empty</strong> sequence of elements within an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,1,1], k = 2
<strong>Output:</strong> 2
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3], k = 3
<strong>Output:</strong> 2
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>-10<sup>7</sup> &lt;= k &lt;= 10<sup>7</sup></code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: C++ Easy solution prefix sum map easy-understanding hashmap
**Author**: [@123_tripathi](https://leetcode.com/123_tripathi/)
**Upvotes**: 562 👍
**Link**: [View Original Post](https://leetcode.com/problems/subarray-sum-equals-k/solutions/1760146/)

---

```
//PLEASE UPVOTE IF YOU LIKE MY SOLUTION  :)
int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        mp[sum] = 1;
        for(auto it:nums){
            sum += it;
            int find = sum - k;
            if(mp.find(find) != mp.end()){
                ans += mp[find];
            }
            mp[sum]++;
        }
        return ans;
//PLEASE UPVOTE IF YOU LIKE MY SOLUTION  :)
    }
```

</details>
