# Remove K Digits

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 15, 2026 |
| **Tags** | String, Stack, Greedy, Monotonic Stack |
| **Link** | [View Problem](https://leetcode.com/problems/remove-k-digits/) |
| **Runtime** | 0 ms |
| **Memory** | 11 MB |

## Problem Description

<p>Given string num representing a non-negative integer <code>num</code>, and an integer <code>k</code>, return <em>the smallest possible integer after removing</em> <code>k</code> <em>digits from</em> <code>num</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> num = "1432219", k = 3
<strong>Output:</strong> "1219"
<strong>Explanation:</strong> Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> num = "10200", k = 1
<strong>Output:</strong> "200"
<strong>Explanation:</strong> Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> num = "10", k = 2
<strong>Output:</strong> "0"
<strong>Explanation:</strong> Remove all the digits from the number and it is left with nothing which is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= num.length &lt;= 10<sup>5</sup></code></li>
	<li><code>num</code> consists of only digits.</li>
	<li><code>num</code> does not have any leading zeros except for the zero itself.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: C++ solution 8ms with detailed explanation
**Author**: [@Leodicap99](https://leetcode.com/Leodicap99/)
**Upvotes**: 350 👍
**Link**: [View Original Post](https://leetcode.com/problems/remove-k-digits/solutions/607570/)

---

```
The way to solve this question is using a stack.
We initally push an element into tthe stack(non zero).
When we encounter the next element we check if it is smaller than the element present in the stack if so pop the element from
the stack and push this element.Why? because he current element has the cacpacity of producting a smaller number as compared to the latter.But we have to limit the pops upto k(cuz only k deletions allowed).
Let us use an example to understand it better:-
num = "1432219", k = 3
we first push 1 into the stack
           |         |
           |         |
           |         |   <-----Stack representation
           |   1     |
           |_________|

now we encounter 4 we check if 4 is lesser than 1 as it is not we push into the stack.

           |         |
           |         |
           |         |   <-----Stack representation
           |   4     |
           |___1_____|

then 3 comes as it is lesser than the top of the stack we pop 4 out and we push 3 in while simultaneously decrementing k . 

           |         |
           |         |
           |         |   <-----Stack representation  k=2
           |   3     |
           |___1_____|

2 beats 3 so 3 is popped out and 2 is pushed and k is decremented.

           |         |
           |         |
           |         |   <-----Stack representation  k=1
           |   2     |
           |___1_____|
2 doesnt beat 2 so it is pushed into the stack

           |         |
           |         |
           |   2     |   <-----Stack representation
           |   2     |
           |___1_____|
1 beats 2 so 2 is popped out and 1 is pushed in.

           |         |
           |         |
           |   1     |   <-----Stack representation   k=0
           |   2     |
           |___1_____|    
now we have the push whatever number is left as we have used up all our deletions

           |         |
           |   9     |
           |   1     |   <-----Stack representation
           |   2     |
           |___1_____|

           answer:-1219.

We will take another example to make sure our algorithm doesnt have leading 0s.

num = "10200", k = 1

           |         |
           |         |
           |         |   <-----Stack representation
           |   1     |
           |_________|
0 beats 1 but we should push 0 as this will cause leading zeros so we push the element if(ans.size()||c!=\'0\') meaning
if ans.size()==0 and c==\'0\' it wouldnt push.

but we wedelete 1 as we have to fulfil the condition of the number of deleteions.

           |         |
           |         |
           |         |   <-----Stack representation   k=0
           |   2     |
           |_________|

           push  rest of the elements by making use of if(ans.size()||c!=\'0\')push(element).



           |         |
           |   0     |
           |   0     |   <-----Stack representation   k=0
           |   2     |
           |_________|


           answer is 200
For optimization purposes we use a string as stack (s.push_back() and s.pop_back()).

    string removeKdigits(string num, int k) {
        string ans="";
        for(char &c:num)
        {
            while(ans.size() && ans.back()>c &&k)
            {
                ans.pop_back();
                k--;
            }
            if(ans.size()||c!=\'0\')ans.push_back(c);
        }
        while(ans.size()&&k--)           <-------this look is to make sure we fulfil the deletion condition
        {
            ans.pop_back();
        }
        return (ans=="")?"0":ans;
    }
```

</details>
