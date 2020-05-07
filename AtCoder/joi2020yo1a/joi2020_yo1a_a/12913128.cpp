// detail: https://atcoder.jp/contests/joi2020yo1a/submissions/12913128
#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int cnt[2]={0};
  cnt[a-1]++;
  cnt[b-1]++;
  cnt[c-1]++;
  if(cnt[0]>cnt[1]){
    cout<<1<<endl;
  }else{
    cout<<2<<endl;
  }
}