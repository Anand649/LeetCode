# Jump Game III

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 9, 2026 |
| **Tags** | Array, Depth-First Search, Breadth-First Search |
| **Link** | [View Problem](https://leetcode.com/problems/jump-game-iii/) |
| **Runtime** | 0 ms |
| **Memory** | 31.6 MB |

## Problem Description

<p>Given an array of non-negative integers <code>arr</code>, you are initially positioned at <code>start</code>&nbsp;index of the array. When you are at index <code>i</code>, you can jump&nbsp;to <code>i + arr[i]</code> or <code>i - arr[i]</code>, check if you can reach&nbsp;<strong>any</strong> index with value 0.</p>

<p>Notice that you can not jump outside of the array at any time.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [4,2,3,0,3,1,2], start = 5
<strong>Output:</strong> true
<strong>Explanation:</strong> 
All possible ways to reach at index 3 with value 0 are: 
index 5 -&gt; index 4 -&gt; index 1 -&gt; index 3 
index 5 -&gt; index 6 -&gt; index 4 -&gt; index 1 -&gt; index 3 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [4,2,3,0,3,1,2], start = 0
<strong>Output:</strong> true 
<strong>Explanation: 
</strong>One possible way to reach at index 3 with value 0 is: 
index 0 -&gt; index 4 -&gt; index 1 -&gt; index 3
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [3,0,2,1,2], start = 2
<strong>Output:</strong> false
<strong>Explanation: </strong>There is no way to reach at index 1 with value 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= arr[i] &lt;&nbsp;arr.length</code></li>
	<li><code>0 &lt;= start &lt; arr.length</code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: C++ easy to solve solution || Beginner friendly algo with detailed explanation and a dry run
**Author**: [@Cosmic_Phantom](https://leetcode.com/Cosmic_Phantom/)
**Upvotes**: 93 👍
**Link**: [View Original Post](https://leetcode.com/problems/jump-game-iii/solutions/1618994/)

---

**Recursive Doge || Doge jumper Algorithm || DFS+Recursion logic**

**Intuition:)**
After reading the question we get the gist that we have to reach the index were value is 0 by jumping left and right ,so the best intuition we get is recursion. So now let\'s think of approach ;)

**Algorithm :**
1. First let\'s think of edge case when our starting location and destination are same. well this is the best case scenerio so we just return true.
2. From the intuition we know we have to jump left and right ,so before jumping we need to check if we have already been there or not . Thus to mark the visited locations we mark them as -1
3. arr[start] should be marked as visited yup, you guessed it correctly , since we start form arr[start] it should be marked as -1 ;]
4. Now if righside is less then arr.size() then do the rightside recursion  or if leftside is > 0 then we have to do leftside recursion .
5. Kaboom that\'s it  .

**Before starting with code let\'s take a dry run:**
![image](https://assets.leetcode.com/users/images/62feb19a-d5be-4c35-88c7-4457eb2b3613_1639019116.2731197.jpeg)



**Code:-**
```
//Comment and Upvote :)

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        //if we have already visited that value , we return false
        if(arr[start]== -1) return false;
        //best case scenerio will be if arr[start] is 0 so we return true
        if(!arr[start]) return true;
        //For leftside and rightside jumps       
        int leftside= start-arr[start] ,rightside = start+arr[start];
        //since we start from arr[start] it should be marked as visited
        arr[start] = -1;
        
        //Now the scenerio were arr[start] != 0 then we need to check if we can either jump to leftside or rightside i.e recursively 
        return rightside = (rightside < arr.size() && canReach(arr,rightside) ) || (leftside>=0 && canReach(arr,leftside) );
    }
};
```
**Time Complexity:** ***`O(n)`*** we are visiting an index only once, in worst can we have to visit all the index lets say we have [1, 1, 1, 1, 1, 1, 0] and start is index = 0
**Space Complexity:** ***`O(1)`*** we are not using any extra space (if we are not counting recursion stack ).

***


..... *Continuation from the previous posts,
A mysterious call came to one of the archelogist who were inspecting the ruins of Dr Cheems Doge\'s lab. The mysterious caller told that do not make mistake of opening the ancient ruins of Dr.Cheems if that opens many things will rise from the ground and shake the entire reality of  earth. After giving that warning the mysterious man disconnected. The archealogist argues about the authenticity of that call .[While in background one of the caged door was vibrating* ...]  *To be continued in the next post*......... 



</details>
