# Maximum Sum of Distinct Subarrays With Length K

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 6, 2026 |
| **Tags** | Array, Hash Table, Sliding Window |
| **Link** | [View Problem](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/) |
| **Runtime** | 124 ms |
| **Memory** | 99.8 MB |

## Problem Description

<p>You are given an integer array <code>nums</code> and an integer <code>k</code>. Find the maximum subarray sum of all the subarrays of <code>nums</code> that meet the following conditions:</p>

<ul>
	<li>The length of the subarray is <code>k</code>, and</li>
	<li>All the elements of the subarray are <strong>distinct</strong>.</li>
</ul>

<p>Return <em>the maximum subarray sum of all the subarrays that meet the conditions</em><em>.</em> If no subarray meets the conditions, return <code>0</code>.</p>

<p><em>A <strong>subarray</strong> is a contiguous non-empty sequence of elements within an array.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,5,4,2,9,9,9], k = 3
<strong>Output:</strong> 15
<strong>Explanation:</strong> The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [4,4,4], k = 3
<strong>Output:</strong> 0
<strong>Explanation:</strong> The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: ✅✅✅ C++ Solution using Map || Very Simple and Easy to Understand
**Author**: [@kreakEmp](https://leetcode.com/kreakEmp/)
**Upvotes**: 109 👍
**Link**: [View Original Post](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/solutions/2783127/)

---

<b>Up Vote if you like the solution
```

/*
Approach is to store the elements in a map and using sliding window technique
check if the size of map is equal to k on each window. The window which has map size equal to k
is having distict elements.

1. Store first k elements in the map.
2. Then keep traversing through the array and adding the new one to the map and 
removing the old one(i-k th) element form the map if its count is zero.
3. Do same for the total sum, add ith value and remove i-k th value.
4. Maximize ans by taking max sum value. 
*/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, sum = 0;
        unordered_map<int, int> mp;
        int i = 0;
        while(i < k  && i < nums.size()){ // store first k elements in the map
            mp[nums[i]]++;
            sum += nums[i];
            i++;
        }
        if(mp.size() == k) ans = sum; // if all distinct, then ans = sum 
        while(i < nums.size()){
            mp[nums[i]]++;
            mp[nums[i-k]]--;
            if(mp[nums[i-k]] == 0) mp.erase(nums[i-k]);
            
            sum += nums[i];
            sum -= nums[i-k];
            if(mp.size() == k) ans = max(ans, sum);
            i++;
        }
        return ans;
    }
};
```
---


<b>Here is an article of my interview experience - A Journey to FAANG Company, I recomand you to go through this to know which all resources I have used & how I cracked interview at Amazon:
https://leetcode.com/discuss/interview-experience/3171859/Journey-to-a-FAANG-Company-Amazon-or-SDE2-(L5)-or-Bangalore-or-Oct-2022-Accepted


---

</details>
