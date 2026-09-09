class Solution {
public:
    bool canReach(vector<int>& nums, int start) {
        int n=nums.size();
        if(n==1) return true;
        if(nums[start]==0) return true;
        vector<int> visited(n,0);
        queue<int> q;
        q.push({start});
        visited[start]=1;
        while(!q.empty())
        {
            auto r = q.front();
            q.pop();
            int back=r-nums[r];
            int forward = r+nums[r];
            if(back>=0 && visited[back]==0)
            {
                if(nums[back]==0) return true;
                q.push({back});
                visited[back]=1;
            }
            if(forward<=n-1 && visited[forward]==0)
            {
                if(nums[forward]==0) return true;
                q.push({forward});
                visited[forward]=1;
            }
        }
        return false;
    }
};