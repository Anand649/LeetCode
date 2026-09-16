class Solution {
public:
    string smallestSubsequence(string s) {
        string st;
        unordered_map<char,int> freq;
        unordered_map<char,bool> check;
        for(char ch:s)
        {
            freq[ch]++;
        }
        for(char ch:s)
        {
            while(!st.empty() && ch<st.back() && freq[st.back()]>1 && !check[ch])
            {
                freq[st.back()]-=1;
                check[st.back()]=false;
                st.pop_back();
            }
            if(check[ch]==false)
            {
                st.push_back(ch);
                check[ch]=true;
            }
            else{
                freq[ch]-=1;
            }
        }
        return st;
    }
};