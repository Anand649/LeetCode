class Solution {
public:
    void recur(vector<vector<int>>& img, int i,int j, vector<vector<int>>& ans)
    {
        int dr[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        int aval=1;
        long long sum=img[i][j];
        for(auto dir:dr)
        {
            int nr = i + dir[0];
            int nc = j + dir[1];
            if(nr>=0 && nr<ans.size() && nc>=0 && nc<ans[0].size())
            {
                aval++;
                sum+=img[nr][nc];
            }
        }
        int average = sum/aval;
        ans[i][j]=average;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img){
        int n=img.size();
        int m=img[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                recur(img,i,j,ans);
            }
        }
        return ans;

    }
};