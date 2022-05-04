// detail: https://atcoder.jp/contests/abc045/submissions/21980585
#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T1, typename T2> ostream &operator<<(ostream &os,const pair<T1,T2> &p) { os<<p.first<<' '<<p.second; return os;}
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ull = unsigned long long;
using ll = long long;
using Pll = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

int main() {
  vector<string> s(3);
  range(i,0,3){
    cin>>s[i];
    reverse(s[i].begin(),s[i].end());
  }

  int ans;
  int turn=0;
  while(1){
    turn=s[turn].back()-'a';
    s[turn].pop_back();
    if(s[turn].empty()){
      ans=turn;
      break;
    }
  }
  vector<char> c={'A','B','C'};
  cout<<c[ans]<<endl;
}