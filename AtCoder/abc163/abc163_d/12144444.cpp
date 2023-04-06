// detail: https://atcoder.jp/contests/abc163/submissions/12144444
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<stdlib.h>
#include<vector>
#define P 1000000000+7
typedef long long int lli;
using namespace std;

void yespr(){cout<<"Yes\n"<<endl;}
void nopr(){cout<<"No\n"<<endl;}
lli comb(lli n,lli r){
    vector<vector<long long>>v(n+1,vector<long long>(n+1,0));
    for(lli i=0;i<v.size();i++){
        v[i][0]=1;
        v[i][i]=1;
    }
    for(lli j=1;j<v.size();j++){
        for(lli k=1;k<j;k++){
            v[j][k]=(v[j-1][k-1]+v[j-1][k]);
        }
    }
    return v[n][r];
}

int main(void){
    lli n,k;

    cin>>n>>k;
    lli sum=0;
    for(lli i=k;i<=n;i++){
        sum+=comb(n+1,i);
        sum%=P;
    }
    if(k>n)cout<<1<<endl;
    else cout<<sum<<endl;
    return 0;
}