class Solution {
public:
    string removeDuplicateLetters(string s){
        string st;
        unordered_map<char,int> freq;
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]]++;
        }
        unordered_map<char,int> check;
        for(char ch:s)
        {
            while(!st.empty() && ch<st.back() && freq[st.back()] > 1 && !check[ch])
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