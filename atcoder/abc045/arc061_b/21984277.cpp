// detail: https://atcoder.jp/contests/abc045/submissions/21984277
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

ll h,w,n;
set<Pll> point_set;
constexpr int dy[]={-1,-1,-1,0,0,0,1,1,1};
constexpr int dx[]={-1,0,1,-1,0,1,-1,0,1};
vector<ll> cnt(10,0);
map<Pll,bool> mp;

bool isRange(int y,int x){
  return 0<=y&&y<h&&0<=x&&x<w;
}

int count_black(int sy,int sx){
  int res=0;
  range(i,0,3) range(j,0,3){
    int ny=sy+i;
    int nx=sx+j;
    if(point_set.find(P(ny,nx))!=point_set.end()){
      res++;
    }
  }
  return res;
}

void dfs(int y,int x,int depth){
  if(depth==2){
    if(!isRange(y,x)) return;
    if(!isRange(y+2,x+2)) return;
    if(mp[P(y,x)]) return;
    cnt[count_black(y,x)]++;
    mp[P(y,x)]=true;
    return;
  }

  range(j,0,9){
    int ny=y+dy[j];
    int nx=x+dx[j];
    dfs(ny,nx,depth+1);
  }
}

int main() {
  cin>>h>>w>>n;
  vector<Pll> ps(n);
  range(i,0,n){
    auto &[y,x]=ps[i];
    cin>>y>>x;
    y--;
    x--;
    point_set.insert(ps[i]);
  }

  range(i,0,n){
    auto [y,x]=ps[i];
    //cerr<<"y:"<<y<<" x:"<<x<<endl;

    dfs(y,x,0);
  }

  ll sum=(h-2)*(w-2);
  range(i,1,10) sum-=cnt[i];
  cnt[0]=sum;

  range(i,0,10){
    cout<<cnt[i]<<newl;
  }
}