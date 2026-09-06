class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> freq;
        int prefix=0;
        freq[0]=1;
        
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            prefix+=nums[i];
            if(freq.count(prefix-k))
            {
                count+=freq[prefix-k];
            }
            freq[prefix]++;
        }
        return count;
    }
};