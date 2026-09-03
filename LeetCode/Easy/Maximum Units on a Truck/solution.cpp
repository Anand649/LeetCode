class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] > b[1];
        });
        int sum=0;
        for(auto box:boxTypes)
        {
            if(truckSize==0) break;
            sum+=min(box[0],truckSize)*box[1];
            truckSize-= min(box[0],truckSize);
        }
        return sum;
    }
};