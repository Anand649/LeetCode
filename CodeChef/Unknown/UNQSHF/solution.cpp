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
        string s1,s2;
        int a1=0,b1=0,a2=0,b2=0;
        cin>>s1>>s2;
        for(char ch: s1)
        {
            if(ch=='a') a1++;
        }
        b1=n-a1;
        for(char ch:s2)
        {
            if(ch=='a') a2++;
        }
        b2 = n-a2;
        if(a1+a2==n)
        {
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
