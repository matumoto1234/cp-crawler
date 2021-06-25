// detail: https://atcoder.jp/contests/abc206/submissions/23732163
#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
  long long l,r;
  cin >> l >> r;
  long long res=0;
  vector<int> cnt(1048576,0);
  for(long long i=2;i<=r;i++){
    if(cnt[i]!=0){continue;}
    for(long long j=i;j<=r;j+=i){cnt[j]++;}
    for(long long j=i*i;j<=r;j+=i*i){cnt[j]=-1000000007;}
  }
  for(long long i=2;i<=r;i++){
    if(cnt[i]<0){continue;}
    long long cc=(r/i)-((l-1)/i);
    if(cnt[i]%2){res+=(cc*(cc-1))/2;}
    else{res-=(cc*(cc-1))/2;}
  }
  for(long long i=max(2ll,l);i<=r;i++){res-=(r/i-1);}
  cout << 2*res << '\n';
  return 0;
}
