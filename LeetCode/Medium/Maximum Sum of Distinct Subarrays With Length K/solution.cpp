class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int> st;
        long long maxi=0,sum=0;

        int i=0;
        for(int j=0;j<nums.size();j++)
        {
            while(st.count(nums[j]))
            {
                st.erase(nums[i]);
                sum-=nums[i];
                i++;
            }

            st.insert(nums[j]);
            sum+=nums[j];

            if(j-i + 1 == k)
            {
                maxi = max(sum,maxi);
                st.erase(nums[i]);
                sum-=nums[i];
                i++;
            }
        }  
        return maxi;
    }
};