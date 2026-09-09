#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        unordered_map<int,int> freq;
        for(int i:a)
        {
            freq[i]++;
        }
        int maxi=0;
        for(auto &pair: freq)
        {
            maxi = max(maxi,pair.second);
        }
        cout<< ceil(maxi/2.0)<<endl;
    }
}
