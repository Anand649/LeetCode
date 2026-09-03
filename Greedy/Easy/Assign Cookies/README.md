# Assign Cookies

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | September 3, 2026 |
| **Tags** | Array, Two Pointers, Greedy, Sorting, Quicksort |
| **Link** | [View Problem](https://leetcode.com/problems/assign-cookies/) |
| **Runtime** | 4 ms |
| **Memory** | 45.1 MB |

## Problem Description

<p>Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.</p>

<p>Each child <code>i</code> has a greed factor <code>g[i]</code>, which is the minimum size of a cookie that the child will be content with; and each cookie <code>j</code> has a size <code>s[j]</code>. If <code>s[j] &gt;= g[i]</code>, we can assign the cookie <code>j</code> to the child <code>i</code>, and the child <code>i</code> will be content. Your goal is to maximize the number of your content children and output the maximum number.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> g = [1,2,3], s = [1,1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> g = [1,2], s = [1,2,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong> You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= g.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= s.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= g[i], s[j] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Note:</strong> This question is the same as <a href="https://leetcode.com/problems/maximum-matching-of-players-with-trainers/description/" target="_blank"> 2410: Maximum Matching of Players With Trainers.</a></p>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: ✅O(n log n) Time O(1) Space - C++/Java/Python/JS - Explained - Sorting
**Author**: [@lancertech6](https://leetcode.com/lancertech6/)
**Upvotes**: 146 👍
**Link**: [View Original Post](https://leetcode.com/problems/assign-cookies/solutions/4485308/)

---

![Screenshot 2024-01-01 083826.png](https://assets.leetcode.com/users/images/6a1053f6-e758-4318-900e-a3be7fb3d665_1704078557.3810096.png)

# YouTube Video Explanation:

<!-- [https://youtu.be/6L_25hyF14s](https://youtu.be/6L_25hyF14s) -->
<!-- **If you want a video for this question please write in the comments** -->

<!-- https://www.youtube.com/watch?v=ujU-jeO1v-k -->
https://youtu.be/ujU-jeO1v-k

**\uD83D\uDD25 Please like, share, and subscribe to support our channel\'s mission of making complex concepts easy to understand.**

Subscribe Link: https://www.youtube.com/@leetlogics/?sub_confirmation=1

*Subscribe Goal: 1100 Subscribers*
*Current Subscribers: 1058*

---

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
To maximize the number of content children, we should try to assign cookies starting from the child with the highest greed factor. Sorting both the greed factors and cookie sizes in allows us to efficiently match larger cookies with children having higher greed factors.

# Approach
<!-- Describe your approach to solving the problem. -->
1. Sort the arrays `g` (greed factors) and `s` (cookie sizes).
2. Initialize variables `maxNum`, `cookieIndex`, and `childIndex` to keep track of the count of content children, the current cookie index, and the current child index, respectively.
3. Iterate through the arrays, comparing the size of the current cookie (`s[cookieIndex]`) with the greed factor of the current child (`g[childIndex]`).
4. If the current cookie is large enough, increment `maxNum`, and move to the next smaller cookie and smaller child.
5. If the current cookie is not large enough, move to the next smaller child.
6. Continue this process until either the cookies or the children are exhausted.
7. Return the final count of content children (`maxNum`).

# Complexity
- Time complexity: The time complexity is O(n log n), where n is the length of the larger array between `g` and `s`, due to the sorting step.
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: The space complexity is O(1).
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```java []
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        int cookiesNums = s.length;
        if(cookiesNums == 0)  return 0;
        Arrays.sort(g);
        Arrays.sort(s);

        int maxNum = 0;
        int cookieIndex = cookiesNums - 1;
        int childIndex = g.length - 1;
        while(cookieIndex >= 0 && childIndex >=0){
            if(s[cookieIndex] >= g[childIndex]){
                maxNum++;
                cookieIndex--;
                childIndex--;
            }
            else{
                childIndex--;
            }
        }

        return maxNum;
    }
}
```
```C++ []
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cookiesNums = s.size();
        if(cookiesNums == 0)  return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int maxNum = 0;
        int cookieIndex = cookiesNums - 1;
        int childIndex = g.size() - 1;
        while(cookieIndex >= 0 && childIndex >=0){
            if(s[cookieIndex] >= g[childIndex]){
                maxNum++;
                cookieIndex--;
                childIndex--;
            }
            else{
                childIndex--;
            }
        }
        return maxNum;
    }
};
```
```Python []
class Solution(object):
    def findContentChildren(self, g, s):
        cookiesNums = len(s)
        if cookiesNums == 0:
            return 0
        g.sort()
        s.sort()

        maxNum = 0
        cookieIndex = cookiesNums - 1
        childIndex = len(g) - 1
        while cookieIndex >= 0 and childIndex >= 0:
            if s[cookieIndex] >= g[childIndex]:
                maxNum += 1
                cookieIndex -= 1
                childIndex -= 1
            else:
                childIndex -= 1

        return maxNum
        
```
```JavaScript []
/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
var findContentChildren = function(g, s) {
    const cookiesNums = s.length;
    if (cookiesNums === 0) return 0;
    g.sort((a, b) => a-b);
    s.sort((a, b) => a-b);

    let maxNum = 0;
    let cookieIndex = cookiesNums - 1;
    let childIndex = g.length - 1;
    while (cookieIndex >= 0 && childIndex >= 0) {
        if (s[cookieIndex] >= g[childIndex]) {
            maxNum++;
            cookieIndex--;
            childIndex--;
        } else {
            childIndex--;
        }
    }
    return maxNum;
};
```
![upvote.png](https://assets.leetcode.com/users/images/0cecb2fa-ca2a-40cc-b6cb-09c2f3417616_1704078969.608004.png)


</details>
