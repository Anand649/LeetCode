class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        while(low<high)
        {
            int mid = low + (high-low)/2;
            if(mid>0 && nums[mid-1]> nums[mid]) return nums[mid];
            if(mid<nums.size() && nums[mid+1]<nums[mid]) return nums[mid+1];
            if(nums[mid]>nums[high]){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return nums[low];
    }
};