# Sudoku Solver

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Hard |
| **Language** | cpp |
| **Solved On** | September 6, 2026 |
| **Tags** | Array, Hash Table, Backtracking, Matrix, Algorithm X, Dancing Links |
| **Link** | [View Problem](https://leetcode.com/problems/sudoku-solver/) |
| **Runtime** | 697 ms |
| **Memory** | 9 MB |

## Problem Description

<p>Write a program to solve a Sudoku puzzle by filling the empty cells.</p>

<p>A sudoku solution must satisfy <strong>all of the following rules</strong>:</p>

<ol>
	<li>Each of the digits <code>1-9</code> must occur exactly once in each row.</li>
	<li>Each of the digits <code>1-9</code> must occur exactly once in each column.</li>
	<li>Each of the digits <code>1-9</code> must occur exactly once in each of the 9 <code>3x3</code> sub-boxes of the grid.</li>
</ol>

<p>The <code>'.'</code> character indicates empty cells.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png" style="height: 250px; width: 250px;">
<pre><strong>Input:</strong> board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
<strong>Output:</strong> [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
<strong>Explanation:</strong>&nbsp;The input board is shown above and the only valid solution is shown below:

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png" style="height: 250px; width: 250px;">
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>board.length == 9</code></li>
	<li><code>board[i].length == 9</code></li>
	<li><code>board[i][j]</code> is a digit or <code>'.'</code>.</li>
	<li>It is <strong>guaranteed</strong> that the input board has only one solution.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: ✅☑️ Best C++ Solution Ever || Easy Solution || Backtracking || One Stop Solution.
**Author**: [@its_vishal_7575](https://leetcode.com/its_vishal_7575/)
**Upvotes**: 65 👍
**Link**: [View Original Post](https://leetcode.com/problems/sudoku-solver/solutions/3226518/)

---

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
We can solve this question Matrix + Backtracking.

# Approach
<!-- Describe your approach to solving the problem. -->
We can easily understand the approach by seeing the code which is easy to understand with comments.

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
Time Complexity : O(9^(N*N)) : For every unassigned index there are 9 possible options so the worst-case time complexity of sudoku solver is O(9^(N*N)).

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
Space Complexity : O(1), Constant space.

# Code
```
/*

    Time Complexity : O(9^(N*N)) : For every unassigned index there are 9 possible options so the worst-case time
    complexity of sudoku solver is O(9^(N*N)).

    Space Complexity : O(1), Constant space.

    Solved using Matrix + Backtracking.

*/

class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch){
        for(int i=0; i<9; i++){
            if(board[i][col] == ch){
                return false;
            }
            if(board[row][i] == ch){
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == ch){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == \'.\'){
                    for(char ch=\'1\'; ch<=\'9\'; ch++){
                        if(isValid(board, i, j, ch)){
                            board[i][j] = ch;
                            if(solve(board) == true){
                                return true;
                            }
                            board[i][j] = \'.\';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

```

***IF YOU LIKE THE SOLUTION THEN PLEASE UPVOTE MY SOLUTION BECAUSE IT GIVES ME MOTIVATION TO REGULARLY POST THE SOLUTION.***

![WhatsApp Image 2023-02-10 at 19.01.02.jpeg](https://assets.leetcode.com/users/images/0a95fea4-64f4-4502-82aa-41db6d77c05c_1676054939.8270252.jpeg)

</details>
