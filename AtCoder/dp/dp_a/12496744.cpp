// detail: https://atcoder.jp/contests/dp/submissions/12496744
#include<bits/stdc++.h>
using namespace std;

int search(int);


vector<int> h(100000);

int main(void){
    int n;
    cin>>n;
    vector<int> dp(n+1);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    /*dp[0]=0;
    dp[1]=abs(h[1]-h[0]);
    for(int i=2;i<n;i++){
        int a=dp[i-1]+abs(h[i]-h[i-1]);
        int b=dp[i-2]+abs(h[i]-h[i-2]);
        if(a>b) dp[i]=b;
        else dp[i]=a;
    }
    cout<<dp[n-1]<<endl;*/
    cout<<search(n-1)<<endl;
    return 0;
}


vector<int> done(100001,0);
vector<int> memo(100001,0);
int search(int a){
    if(a<=0){
        done[a]=1;
        memo[a]=0;
        return 0;
    }
    if(done[a]==1)return memo[a];

    done[a]=1;
    int res;
    int temp=search(a-1)+abs(h[a]-h[a-1]);
    int temp2=search(a-2)+abs(h[a]-h[a-2]);

    if(temp>temp2){
        res=temp2;
    }else{
        res=temp;
    }
    memo[a]=res;

    return res;
}