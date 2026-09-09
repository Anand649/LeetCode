#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        long long x,y;
        cin>>x>>y;
        for(int days=1; days<=x;days++){
            bool flag = false;
            for (int k=1;k<=days;k++){
                long long sumSquares =(1LL * k * (k + 1) * (2 * k + 1))/ 6;
                long long revenue =y*(sumSquares + 1LL * (days - k) * k * k);
                long long cost = x*k;
                if (revenue > cost){
                    flag = true;
                    break;
                }
            }
            if(flag){
                cout<<days<<endl;
                break;
            }
        }
    }

    return 0;
}