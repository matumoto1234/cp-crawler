// detail: https://atcoder.jp/contests/dp/submissions/12404284
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin>>n;
    vector<int> h(n);
    vector<int> dp(n+1);

    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    dp[0]=0;
    dp[1]=abs(h[1]-h[0]);
    for(int i=2;i<n;i++){
        int a=dp[i-1]+abs(h[i]-h[i-1]);
        int b=dp[i-2]+abs(h[i]-h[i-2]);
        if(a>b) dp[i]=b;
        else dp[i]=a;
    }
    cout<<dp[n-1]<<endl;
    return 0;
}