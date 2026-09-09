class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int current = 0;
        int maxpos = 0;
        for(int i=0;i<nums.size()-1;i++)
        {
            maxpos = max(maxpos, i+nums[i]);
            if(i==current)
            {
                jumps++;
                current=maxpos;
            }
        }
        return jumps;
    }
};