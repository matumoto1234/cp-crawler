// detail: https://atcoder.jp/contests/atc001/submissions/20786764
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

struct GridBFS{
  int H,W;
  vector<int> dy,dx;
  vector<vector<char>> s;
  GridBFS(int h,int w):H(h),W(w),s(h,vector<char>(w)),
  dy({0,1,0,-1}),
  dx({1,0,-1,0}){}

  bool rangeCheck(int y,int x){ return 0<=y&&y<H&&0<=x&&x<W; }

  vector<vector<int>> build(int sy,int sx){
    vector<vector<int>> arrived(H,vector<int>(W,-1));
    arrived[sy][sx]=0;
    queue<pair<int,int>> q;
    q.emplace(sy,sx);

    while(!q.empty()){
      auto [y,x] = q.front();
      q.pop();
      for(int i=0;i<4;i++){
        int ny=y+dy[i], nx=x+dx[i];
        if(!rangeCheck(ny,nx)) continue;
        if(s[ny][nx]=='#') continue;
        if(arrived[ny][nx]!=-1) continue;
        arrived[ny][nx]=arrived[y][x]+1;
        q.emplace(ny,nx);
      }
    }
    return arrived;
  }
  vector<char> &operator[](int y){ return s[y]; }
};

/*
// 隣接している同じ色でグループを作る
// cntはグループの数
vector<vector<int>> buildGroup(int &cnt){
  cnt=0;
  vector<vector<int>> group(H,vector<int>(W,-1));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(group[i][j]!=-1) continue;
      group[i][j]=cnt;
      queue<pair<int,int>> q;
      q.emplace(i,j);
      char c = s[i][j];

      while(!q.empty()){
        auto [y,x] = q.front();
        q.pop();
        for(int i=0;i<4;i++){
          int ny=y+dy[i], nx=x+dx[i];
          if(!rangeCheck(ny,nx)) continue;
          if(s[ny][nx] != c) continue;
          if(group[ny][nx] != -1) continue;
          group[y][x]=cnt;
          q.emplace(ny,nx);
        }
      }
      cnt++;
    }
  }
  return group;
}
*/

int main() {
  int h,w;
  cin>>h>>w;
  int sy,sx,gy,gx;
  GridBFS s(h,w);
  range(i,0,h) range(j,0,w){
    cin>>s[i][j];
    if(s[i][j]=='s'){
      sy=i;
      sx=j;
    }
    if(s[i][j]=='g'){
      gy=i;
      gx=j;
    }
  }

  vector<vector<int>> arrived = s.build(sy,sx);
  cout<<(arrived[gy][gx]!=-1?"Yes":"No")<<endl;
}