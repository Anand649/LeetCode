# Smallest Subsequence of Distinct Characters

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 16, 2026 |
| **Tags** | String, Stack, Greedy, Monotonic Stack |
| **Link** | [View Problem](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/) |
| **Runtime** | 1 ms |
| **Memory** | 8.9 MB |

## Problem Description

<p>Given a string <code>s</code>, return <em>the </em><span data-keyword="lexicographically-smaller-string" class=" cursor-pointer relative text-dark-blue-s text-sm"><button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-_r_u_" data-state="closed" class=""><em>lexicographically smallest</em></button></span> <span data-keyword="subsequence-string" class=" cursor-pointer relative text-dark-blue-s text-sm"><button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-_r_v_" data-state="closed" class=""><em>subsequence</em></button></span><em> of</em> <code>s</code> <em>that contains all the distinct characters of</em> <code>s</code> <em>exactly once</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "bcabc"
<strong>Output:</strong> "abc"
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "cbacdcbc"
<strong>Output:</strong> "acdb"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>

<p>&nbsp;</p>
<strong>Note:</strong> This question is the same as 316: <a href="https://leetcode.com/problems/remove-duplicate-letters/" target="_blank">https://leetcode.com/problems/remove-duplicate-letters/</a>

##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: [C++] Stack-based Solution Explained, 100% Time, ~50% Space
**Author**: [@Ajna](https://leetcode.com/Ajna/)
**Upvotes**: 5 👍
**Link**: [View Original Post](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/solutions/891944/)

---

Now we have a tricky one to rein in, since we might be tempted to go for some approaches that would collapse once you factor in some specific scenarios.

My solution might not be the perfect one, but I found it to be rather understandable and, not secondarily, performing enough, so allow me to go into more detail about it.

We start with our usual support variables:
* `res` will store our result, as usual;
* `st` (I know, again: I really suck at naming) is a stack of character we will use to figure out what to keep and what to discard (more about it later);
* `seen` is an array of `26` booleans, we will initialise to `false`;
* `last`, similarly to the previous, is an array of `26` integers that will store the value of the last indexes of each character in the input -  you don\'t really need initialising it if you use more complex logic, but setting all its values to `0` was easier and cheaper to manage;
* `len` will store the input string size;

First of all we are going to start populating `last` with proper values, starting from the end of the string and moving on either up to the first character or until we have met all possible `26` different ones - which probably is going to be a massive computational save on massive random strings.

Note that here as when using `seen`, we will normalise all characterss to be in the `0 - 25` range subtracting `\'a\'` from their actual value.

Now comes the core of our function: building and updating a stack with all the encountered characters in order; to do so, we will run through the whole string (this time from the beginning) and:
* normalising each character `c`, as explained right above;
* checking if `seen[c]`, in which case we just placidly `continue`;
* otherwise, while we have something in the stack, we pop as long as `c` is lexicographically less than the current `st.top()` and if `i` is before the previously computed last index of the top of the stack (`last[st.top()]`);
* each pop will also make so that we turn the matching cell in `seen` back to `false` (since we need to keep track about how we removed that character from our stack);
* in any case, we add `c` on top of the stack `st`;
* finally, we set `seen[c] = true`.

Once we are done looping through the would string, we can just pop all the content of the stack into our accumulator `res`, just remembering that this process will give us our result string in reverse, so we just have to `reverse` it again and finally can return it :)

The code:

```cpp
class Solution {
public:
    string smallestSubsequence(string s) {
        // support variables
        string res = "";
        stack<char> st;
        bool seen[26];
        for (bool &s: seen) s = false;
        int last[26], len = s.size();
        for (int &l: last) l = 0;
        for (int i = len - 1, charCount = 0; charCount < 26 && i >= 0; i--) {
            // adding the last index when not yet found
            if (!last[s[i] - \'a\']) {
                charCount++;
                last[s[i] - \'a\'] = i;            }
        }
        // building a stack with all the characters in a valid sequence
        for (int i = 0, c; i < len; i++) {
            c = s[i] - \'a\';
            if (seen[c]) continue;
            while (!st.empty() && c < st.top() && i < last[st.top()]) {
                seen[st.top()] = false;
                st.pop();
            }
            st.push(c);
            seen[c] = true;
        }
        // recomposing the string from the stack
        while (!st.empty()) {
            res.push_back(st.top() + \'a\');
            st.pop();
        }
        reverse(begin(res), end(res));
        return res;
    }
};
```

</details>
