// detail: https://atcoder.jp/contests/abc166/submissions/12776354
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(void){
    lli x;

    cin>>x;

    lli xx=20000;

    for(lli i=-xx;i<=xx;i++){
        for(lli j=-xx;j<=xx;j++){
            lli temp=(i*i-j*j)*(i*i+j*j)*(i+j)-i*j*(i+j)*(i*i-i*j+j*j);
            if(temp==x){
                cout<<i<<" "<<j<<endl;
                return 0;
            }
        }
    }

    return 0;
}