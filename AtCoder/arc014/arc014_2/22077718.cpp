// detail: https://atcoder.jp/contests/arc014/submissions/22077718
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
constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr char newl = '\n';

int main() {
  int n;
  cin>>n;
  vector<string> w(n);
  range(i,0,n){
    cin>>w[i];
  }

  int ans=0;
  char pre=w[0].front();
  set<string> set1,set2;

  range(i,0,n){
    if(i%2==0){
      if(pre!=w[i].front()){
        ans=1;
        break;
      }
      if(set1.find(w[i])!=set1.end()){
        ans=1;
        break;
      }
      set1.insert(w[i]);
    }else{
      if(pre!=w[i].front()){
        ans=-1;
        break;
      }
      if(set2.find(w[i])!=set2.end()){
        ans=-1;
        break;
      }
      set2.insert(w[i]);
    }
    pre=w[i].back();
  }

  if(ans==-1) cout<<"WIN"<<endl;
  else if(ans==0) cout<<"DRAW"<<endl;
  else if(ans==1) cout<<"LOSE"<<endl;
}