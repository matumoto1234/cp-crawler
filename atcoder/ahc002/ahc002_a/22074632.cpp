// detail: https://atcoder.jp/contests/ahc002/submissions/22074632
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

constexpr int n=50;
constexpr int dy[]={1,0,-1,0},dx[]={0,1,0,-1};
int sy,sx;
vector<vector<int>> t(n,vector<int>(n));
vector<vector<int>> p(n,vector<int>(n));

//struct edge{
//  int to;
//  ll cost;
//  edge(){}
//  edge(int _to,ll _cost):to(_to),cost(_cost){}
//  bool operator<(const edge &e) const { return cost < e.cost; }
//};
//
//vector<vector<edge>> convertGraph(){
//  vector<vector<edge>> res(n*n);
//  for(int i=0;i<n;i++){
//    for(int j=0;j<n;j++){
//      int from=i*n+j;
//      for(int k=0;k<4;k++){
//        int ny=i+dy[k],nx=j+dx[k];
//        if(ny<0||nx<0||n<=ny||n<=nx) continue;
//        if(t[i][j]==t[ny][nx]) continue;
//        int to=ny*n+j;
//        ll cost=p[ny][nx];
//        res[from].emplace_back(to,cost);
//      }
//    }
//  }
//  return res;
//}

//struct RandomNumberGenerator {
//  mt19937 mt;
//
//  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
//
//  int operator()(int a, int b) { // [a, b)
//    uniform_int_distribution< int > dist(a, b - 1);
//    return dist(mt);
//  }
//
//  int operator()(int b) { // [0, b)
//    return (*this)(0, b);
//  }
//};

//bool isRange(int y,int x,int h,int w){
//  return 0<=y&&y<h&&0<=x&&x<w;
//}
//
//constexpr int limit = 15;
//vector<bool> used(n*n,false);
//vector<ll> ds(n*n,-1);
//ll dfs(int from,int depth,ll sum){
//  if(depth==limit){
//    used[from]=false;
//    ds[from]=-1;
//    return sum;
//  }
//
//  used[from]=true;
//  ll res=0;
//
//  for(auto e:G[from]){
//    if(used[e.to]) continue;
//    bs[e.to]=from;
//
//  }
//  used[from]=false;
//  ds[from]=-1;
//  return res;
//}


vector<vector<bool>> used(n,vector<bool>(n,false));
string ans;

char dir_to_c(int dir){
  if(dir==0) return 'D';
  if(dir==1) return 'R';
  if(dir==2) return 'U';
  return 'L';
}

bool isRange(int y,int x,int h,int w){
  return 0<=y&&y<h&&0<=x&&x<w;
}

void mark(int y,int x){
  used[y][x]=true;
  range(i,0,4){
    int ny=y+dy[i],nx=x+dx[i];
    if(!isRange(ny,nx,n,n)) continue;
    if(t[y][x]==t[ny][nx]) used[ny][nx]=true;
  }
}

void dfs(int y,int x,int dir){
  cerr<<"y:"<<y<<" x:"<<x<<endl;
  mark(y,x);

  range(i,0,4){
    int d=(dir+i)%4;
    int ny=y+dy[d],nx=x+dx[d];
    if(!isRange(ny,nx,n,n)) continue;
    if(!used[ny][nx]){
      // ans.emplace_back(dir_to_c(d));
      ans+=dir_to_c(d);
      dfs(ny,nx,d);
      break;
    }
  }
}


int main() {
  cin>>sy>>sx;
  range(i,0,n) range(j,0,n){
    cin>>t[i][j];
  }
  range(i,0,n) range(j,0,n){
    cin>>p[i][j];
  }

  // cerr<<"hello"<<endl;
  // vector<vector<edge>> graph=convertGraph();
  dfs(sy,sx,0);
  cout<<ans<<endl;
}