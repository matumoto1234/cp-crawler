// detail: https://atcoder.jp/contests/arc105/submissions/17341590
#include <bits/stdc++.h>
using namespace std;


int main()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  int minv;
  minv=1e9+1;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(i){
      minv = min(minv, __gcd(a[i-1],a[i]));
    }
  }
  cout<<minv<<endl;
  return 0;
}