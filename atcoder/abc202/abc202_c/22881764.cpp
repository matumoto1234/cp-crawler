// detail: https://atcoder.jp/contests/abc202/submissions/22881764
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n;
  cin>>n;
  vector<int> a(n),b(n);
  for(int &A:a) cin>>A;
  for(int &B:b) cin>>B;
  
  map<int,ll> mpa;
  for(int A:a){
    mpa[A]++;
  }
  
  ll ans=0;
  for(int i=0;i<n;i++){
    int c;
    cin>>c;
    c--;
    ans += mpa[b[c]];
  }
  cout<<ans<<endl;
}