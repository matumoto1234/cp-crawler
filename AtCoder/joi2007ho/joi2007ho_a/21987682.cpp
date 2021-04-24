// detail: https://atcoder.jp/contests/joi2007ho/submissions/21987682
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;

  cin >> n >> k;

  int a[n];
  for(int i=0; i<n; i++){
    cin >> a[i];
  }

  int cumulative_sum[n+1];
  for(int i=0; i<n+1; i++){
    cumulative_sum[i]=0;
  }

  for(int i=0; i<n; i++){
    cumulative_sum[i+1] += a[i]+cumulative_sum[i];
  }

  int ans=-1000000000-10000;
  for(int i=0; i<n; i++){

    int l=i;
    int r=i+k;

    if(r>n) break;

    // [l, r)
    int sum = cumulative_sum[r]-cumulative_sum[l];

    ans = max(ans,sum);
  }

  cout << ans << endl;
}