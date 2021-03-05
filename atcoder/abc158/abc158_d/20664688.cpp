// detail: https://atcoder.jp/contests/abc158/submissions/20664688
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
using PL = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

int main() {
  string s;
  int q;
  cin>>s>>q;

  int sum=0;
  vector<pair<char,int>> v;
  range(i,0,q){
    int t;
    cin>>t;
    if(t==1){
      sum++;
    }else{
      int f;
      char c;
      cin>>f>>c;
      if(f==1){
        v.emplace_back(c,sum+1);
      }else{
        v.emplace_back(c,sum);
      }
    }
  }

  deque<char> ans;
  range(i,0,s.size()){
    ans.emplace_back(s[i]);
  }

  range(i,0,v.size()){
    auto [c,num]=v[i];
    num=num%2;
    if(num==0){
      ans.emplace_front(c);
    }else{
      ans.emplace_back(c);
    }
  }
  if( abs(sum-v.back().second)%2==1){
    reverse(ans.begin(),ans.end());
  }

  for(char c:ans){
    cout<<c;
  }
  cout<<newl;
}