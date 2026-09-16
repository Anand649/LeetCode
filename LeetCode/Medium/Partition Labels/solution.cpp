class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char,int> freq;
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]]++;
        }      
        unordered_map<char,int> tracker;
        int prev=-1;
        int dist=0;
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            tracker[s[i]]++;
            if(tracker[s[i]]==1) dist++;

            if(tracker[s[i]]==freq[s[i]])
            {
                count++;
            }
            if(count==dist)
            {
                ans.push_back(i-prev);
                dist=0;
                count=0;
                prev=i;
            }
        }
        return ans;
    }
};