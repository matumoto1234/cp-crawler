// detail: https://atcoder.jp/contests/dp/submissions/12408295
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n,k;

    cin>>n>>k;
    vector<int> h(n),dp(n+1);

    for(int i=0;i<n;i++){
        cin>>h[i];
        dp[i]=INT_MAX;
    }
    dp[0]=0;
    dp[1]=abs(h[1]-h[0]);
    for(int i=0;i<n;i++){
        for(int j=1;j<=k;j++){
            int a=dp[i]+abs(h[i+j]-h[i]);
            if(dp[i+j]>a){
                dp[i+j]=a;
            }
        }
    }
    cout<<dp[n-1]<<endl;
    return 0;
}