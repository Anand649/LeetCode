class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int min=arr[0],max=0;
        long long ans=0;
        for(int i=0;i<arr.size();i++)
        {
            if(min>arr[i])
            {
                min=arr[i];
            }
            else if(max<(arr[i]-min)){
                if(i==arr.size()-1  || arr[i]>arr[i+1])
                {
                    ans+=(arr[i]-min);
                    min=INT_MAX;
                }
            }
        }
        return ans;
    }
};