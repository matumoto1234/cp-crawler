// detail: https://atcoder.jp/contests/arc114/submissions/20944736
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

const ll MOD = 998244353;

struct SCC{
  vector<vector<int>> G,rG;
  vector<int> scc;
  vector<int> post_order;
  vector<bool> arrived;

  int cnt;

  SCC(int V):G(V),rG(V){}

  void add_edge(int from,int to){
    G[from].emplace_back(to);
    rG[to].emplace_back(from);
  }

  int build(){
    int V=G.size();
    arrived.assign(V,false);

    for(int i=0;i<V;i++){
      if(arrived[i]) continue;
      dfs(i);
    }

    cnt=0;
    scc.assign(V,0);
    arrived.assign(V,false);

    for(int i=V-1;i>=0;i--){
      int idx=post_order[i];
      if(arrived[idx]) continue;
      rdfs(idx,cnt);
      cnt++;
    }
    return cnt;
  }

  void dfs(int idx){
    arrived[idx]=true;
    for(int to:G[idx]){
      if(arrived[to]) continue;
      dfs(to);
    }
    post_order.emplace_back(idx);
  }

  void rdfs(int idx,int num){
    arrived[idx]=true;
    scc[idx]=num;
    for(int to:rG[idx]){
      if(arrived[to]) continue;
      rdfs(to,num);
    }
  }

  int size() { return cnt; }

  bool issame(int a,int b){ return scc[a]==scc[b]; }

  int operator[](int k){ return scc[k]; }
};

int main() {
  int n;
  cin>>n;
  vector<int> f(n);

  SCC G(n);
  range(i,0,n){
    cin>>f[i];
    f[i]--;
    G.add_edge(i,f[i]);
  }

  G.build();

  map<ll,pair<int,ll>> mp;
  range(i,0,n){
    mp[G[i]].first=i;
    mp[G[i]].second++;
  }

  ll ans=0;
  for(auto [ord,temp]:mp){
    ll id=temp.first;
    ll cnt=temp.second;
    if(cnt==1&&f[id]==id){
      ans++;
    }else if(cnt>=2){
      ans++;
    }
  }

  cout<<((1LL<<ans)-1)%MOD<<endl;
}