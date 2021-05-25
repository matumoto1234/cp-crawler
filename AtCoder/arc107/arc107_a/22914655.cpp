// detail: https://atcoder.jp/contests/arc107/submissions/22914655
#include <bits/stdc++.h>
#include <atcoder/modint.hpp>
using namespace std;
using mint = atcoder::modint998244353;

int main(){
  vector<mint> a(3);
  for(int i=0;i<3;i++){
    int n;
    cin>>n;
    a[i]=n;
  }
  mint ans=1;
  for(int i=0;i<3;i++){
    ans*=(a[i]+1)*(a[i])/2;
  }
  cout<<ans.val()<<endl;
}