// detail: https://atcoder.jp/contests/abc153/submissions/23079781
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> H(N);
  for ( int i = 0; i < N; i++ ) {
    cin >> H[i];
  }
  
  sort( H.rbegin(), H.rend() );
  
  for ( int i = 0; i < K; i++ ) {
    H[i] = 0;
  }
  
  long long ans = 0;
  for ( int i = 0; i < N; i++) {
    ans += H[i];
  }
  cout << ans << endl;
}