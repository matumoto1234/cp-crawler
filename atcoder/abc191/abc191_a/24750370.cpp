// detail: https://atcoder.jp/contests/abc191/submissions/24750370
#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
using ll = long long;
using LP = pair<ll, ll>;
using P = pair<int, int>;
const ll INF = INT64_MAX / 2LL;
const int inf = INT32_MAX / 2;

int main() {
  int v,t,s,d;
  cin>>v>>t>>s>>d;
  if(v*t<=d&&d<=v*s){
    cout<<"No"<<endl;
  }else{
    cout<<"Yes"<<endl;
  }
}