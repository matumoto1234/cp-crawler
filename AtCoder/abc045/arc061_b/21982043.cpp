// detail: https://atcoder.jp/contests/abc045/submissions/21982043
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

bool isRange(int y,int x,int h,int w){
  return 0<=y&&y<=h&&0<=x&&x<=w;
}

set<P> point_set;
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

int main() {
  ll h,w,n;
  cin>>h>>w>>n;
  vector<P> ps(n);
  range(i,0,n){
    auto &[y,x]=ps[i];
    cin>>y>>x;
    y--;
    x--;
    point_set.insert(ps[i]);
  }

  constexpr int dy[]={-1,-1,-1,0,0,0,1,1,1};
  constexpr int dx[]={-1,0,1,-1,0,1,-1,0,1};

  vector<ll> cnt(10,0);
  map<P,bool> mp;
  range(i,0,n){
    auto [y,x]=ps[i];
    cerr<<"y:"<<y<<" x:"<<x<<endl;
    range(j,0,9){
      int ny=y+dy[j];
      int nx=x+dx[j];
      if(!isRange(ny,nx,h,w)) continue;
      if(!isRange(ny+3,nx+3,h,w)) continue;
      if(mp[P(ny,nx)]) continue;

      cnt[count_black(ny,nx)]++;
      cerr<<"ny:"<<ny<<" nx:"<<nx<<" count:"<<count_black(ny,nx)<<endl;
      mp[P(ny,nx)]=true;
    }
  }

  ll sum=(h-2)*(w-2);
  range(i,1,10){
    sum-=cnt[i];
  }
  cnt[0]=sum;

  range(i,0,10){
    cout<<cnt[i]<<endl;
  }
}