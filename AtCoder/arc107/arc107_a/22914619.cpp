// detail: https://atcoder.jp/contests/arc107/submissions/22914619
#include <bits/stdc++.h>
#include <atcoder/modint998244353>
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
    ans*=(a+1)*(a)/2;
  }
  cout<<ans.val()<<endl;
}