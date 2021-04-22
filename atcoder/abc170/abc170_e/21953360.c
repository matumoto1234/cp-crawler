// detail: https://atcoder.jp/contests/abc170/submissions/21953360
#include <bits/stdc++.h>
#include <atcoder/segtree.hpp>
using namespace std;
using namespace atcoder;

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

int op(int a,int b){
  return min(a,b);
}

int e(){
  return INF32;
}

int main() {
  const int NUM=200000;
  int n,q;
  cin>>n>>q;
  vector<set<int>> sets(NUM);
  vector<P> children(n);
  range(i,0,n){
    auto &[a,b]=children[i];
    cin>>a>>b;
    b--;
    sets[b].insert(a);
  }

  vector<int> c(q),d(q);
  range(i,0,q){
    cin>>c[i]>>d[i];
    c[i]--;
    d[i]--;
  }

  segtree<int,op,e> seg(NUM);
  range(i,0,NUM){
    if(sets[i].empty()) continue;
    auto it=sets[i].rbegin();
    seg.set(i,*it);
  }

  range(i,0,q){
    auto [rate,old]=children[c[i]];
    sets[old].extract(rate);
    // if(!sets[old].empty()) pq.emplace(*sets[old].rbegin());
    if(sets[old].empty()) seg.set(old,e());
    else seg.set(old,*sets[old].rbegin());

    // cerr<<"seg[old]:"<<seg.get(old)<<endl;

    sets[d[i]].insert(rate);
    if(seg.get(d[i])==e()||seg.get(d[i])<rate) seg.set(d[i],rate);

    cout<<seg.prod(0,NUM)<<newl;
    //pq.emplace(*sets[d[i]].rbegin());
  }
}