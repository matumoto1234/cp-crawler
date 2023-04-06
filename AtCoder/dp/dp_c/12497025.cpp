// detail: https://atcoder.jp/contests/dp/submissions/12497025
#include<bits/stdc++.h>
using namespace std;

int resmin(int a,int b){return a>b?b:a;}
int resmax(int a,int b){return a>b?a:b;}

int main(int argc,char *argv[]){
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(3));
    vector<vector<int>> dp(n+1,vector<int>(3,0));

    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    for(int i=0;i<3;i++)dp[0][i]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(j==k)continue;
                int temp=dp[i][j]+a[i][k];
                int temp2=dp[i+1][k];

                if(temp>temp2){
                    dp[i+1][k]=temp;
                }
            }
        }
    }
    int max=dp[n][0];
    if(max<dp[n][1]){
        max=dp[n][1];
    }
    if(max<dp[n][2]){
        max=dp[n][2];
    }
    cout<<max<<endl;
}