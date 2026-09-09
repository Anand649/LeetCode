# Jump Game II

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 9, 2026 |
| **Tags** | Array, Dynamic Programming, Greedy |
| **Link** | [View Problem](https://leetcode.com/problems/jump-game-ii/) |
| **Runtime** | 0 ms |
| **Memory** | 20.5 MB |

## Problem Description

<p>You are given a <strong>0-indexed</strong> array of integers <code>nums</code> of length <code>n</code>. You are initially positioned at&nbsp;index 0.</p>

<p>Each element <code>nums[i]</code> represents the maximum length of a forward jump from index <code>i</code>. In other words, if you are at index <code>i</code>, you can jump to any index <code>(i + j)</code>&nbsp;where:</p>

<ul>
	<li><code>0 &lt;= j &lt;= nums[i]</code> and</li>
	<li><code>i + j &lt; n</code></li>
</ul>

<p>Return <em>the minimum number of jumps to reach index </em><code>n - 1</code>. The test cases are generated such that you can reach index&nbsp;<code>n - 1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,3,1,1,4]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,3,0,1,4]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
	<li>It's guaranteed that you can reach <code>nums[n - 1]</code>.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: C++✅✅ | Faster🧭 than 75%🔥| Straight Forward Method🆗 | Clean And Concise Code |
**Author**: [@mr_kamran](https://leetcode.com/mr_kamran/)
**Upvotes**: 525 👍
**Link**: [View Original Post](https://leetcode.com/problems/jump-game-ii/solutions/3158218/)

---


# Code

# Please Do Upvote!!!!
##### Connect with me on Linkedin -> https://www.linkedin.com/in/md-kamran-55b98521a/
```

class Solution {
public:

    int jump(vector<int>& nums) {

      for(int i = 1; i < nums.size(); i++)
      {
        nums[i] = max(nums[i] + i, nums[i-1]);
      }

      int ind = 0;
      int ans = 0;

      while(ind < nums.size() - 1)
      {
        ans++;
        ind = nums[ind];
      }

      return ans;
    }
};


```
![b62ab1be-232a-438f-9524-7d8ca4dbd5fe_1675328166.1161866.png](https://assets.leetcode.com/users/images/24f080eb-397a-4a09-a9f5-6a9a315c955f_1675822350.8603303.png)


</details>
