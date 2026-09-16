# Distinct Subsequences

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Hard |
| **Language** | cpp |
| **Solved On** | September 16, 2026 |
| **Tags** | String, Dynamic Programming |
| **Link** | [View Problem](https://leetcode.com/problems/distinct-subsequences/) |
| **Runtime** | 35 ms |
| **Memory** | 27 MB |

## Problem Description

<p>Given two strings s and t, return <i>the number of distinct</i> <b><i>subsequences</i></b><i> of </i>s<i> which equals </i>t.</p>

<p>The test cases are generated so that the answer fits on a 32-bit signed integer.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "rabbbit", t = "rabbit"
<strong>Output:</strong> 3
<strong>Explanation:</strong>
As shown below, there are 3 ways you can generate "rabbit" from s.
<code><strong><u>rabb</u></strong>b<strong><u>it</u></strong></code>
<code><strong><u>ra</u></strong>b<strong><u>bbit</u></strong></code>
<code><strong><u>rab</u></strong>b<strong><u>bit</u></strong></code>
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "babgbag", t = "bag"
<strong>Output:</strong> 5
<strong>Explanation:</strong>
As shown below, there are 5 ways you can generate "bag" from s.
<code><strong><u>ba</u></strong>b<u><strong>g</strong></u>bag</code>
<code><strong><u>ba</u></strong>bgba<strong><u>g</u></strong></code>
<code><u><strong>b</strong></u>abgb<strong><u>ag</u></strong></code>
<code>ba<u><strong>b</strong></u>gb<u><strong>ag</strong></u></code>
<code>babg<strong><u>bag</u></strong></code></pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 1000</code></li>
	<li><code>s</code> and <code>t</code> consist of English letters.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: 7-10 lines C++ Solutions with Detailed Explanations (O(m*n) time and O(m) space)
**Author**: [@jianchao-li](https://leetcode.com/jianchao-li/)
**Upvotes**: 295 👍
**Link**: [View Original Post](https://leetcode.com/problems/distinct-subsequences/solutions/37316/)

---

Well, a dynamic programming problem. Let's first define its state `dp[i][j]` to be the number of distinct subsequences of `t[0..i - 1]` in `s[0..j - 1]`. Then we have the following state equations:

 1. General case 1: `dp[i][j] = dp[i][j - 1]` if `t[i - 1] != s[j - 1]`;
 2. General case 2: `dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1]` if `t[i - 1] == s[j - 1]`;
 3. Boundary case 1: `dp[0][j] = 1` for all `j`;
 4. Boundary case 2: `dp[i][0] = 0` for all **positive** `i`.

Now let's give brief explanations to the four equations above.

 1. If `t[i - 1] != s[j - 1]`, the distinct subsequences will not include `s[j - 1]` and thus all the number of distinct subsequences will simply be those in `s[0..j - 2]`, which corresponds to `dp[i][j - 1]`;
 2. If `t[i - 1] == s[j - 1]`, the number of distinct subsequences include two parts: those with `s[j - 1]` and those without;
 3. An empty string will have exactly one subsequence in any string :-)
 4. Non-empty string will have no subsequences in an empty string.

Putting these together, we will have the following simple codes (just like translation :-)):

    class Solution {
    public:
        int numDistinct(string s, string t) {
            int m = t.length(), n = s.length();
            vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
            for (int j = 0; j <= n; j++) dp[0][j] = 1;
            for (int j = 1; j <= n; j++)
                for (int i = 1; i <= m; i++)
                    dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
            return dp[m][n];
        }
    };  

Notice that we keep the whole `m*n` matrix simply for `dp[i - 1][j - 1]`. So we can simply store that value in a single variable and further optimize the space complexity. The final code is as follows.

    class Solution {
    public:
        int numDistinct(string s, string t) {
            int m = t.length(), n = s.length();
            vector<int> cur(m + 1, 0);
            cur[0] = 1;
            for (int j = 1; j <= n; j++) { 
                int pre = 1;
                for (int i = 1; i <= m; i++) {
                    int temp = cur[i];
                    cur[i] = cur[i] + (t[i - 1] == s[j - 1] ? pre : 0);
                    pre = temp;
                }
            }
            return cur[m];
        }
    };

</details>
