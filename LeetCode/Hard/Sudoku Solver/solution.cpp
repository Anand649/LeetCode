class Solution {
public:
    bool rowandcol(vector<vector<char>>& board,int row,int col)
    {
        for(int i=0;i<9;i++)
        {
            if(i==row) continue;
            if(board[i][col]==board[row][col]) return false;
        }
        for(int j=0;j<9;j++)
        {
            if(j==col) continue;
            if(board[row][j]==board[row][col]) return false;
        }
        return true;
    }
    bool box(vector<vector<char>>& board,int row,int col)
    {
        int box_row=(row/3)*3;
        int box_col=(col/3)*3;
        for(int i=box_row;i<box_row+3;i++)
        {
            for(int j=box_col;j<box_col+3;j++)
            {
                if(row==i && col==j) continue;
                if(board[i][j]==board[row][col]) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char curr='1';curr<='9';curr++)
                    {
                        board[i][j]=curr;
                        if(rowandcol(board,i,j) && box(board,i,j))
                        {
                            if(solve(board)) return true;
                        }        
                        board[i][j]='.';
                    } 
                    return false;
                }
                
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};