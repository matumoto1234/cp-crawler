// detail: https://atcoder.jp/contests/joi2011yo/submissions/21049259
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

int h,w,n;

vector< vector< int > > grid_bfs(vector< string > &s, char start, const string &wall = "#") {
  const int vx[] = {0, 1, 0, -1}, vy[] = {1, 0, -1, 0};
  vector< vector< int > > min_cost(s.size(), vector< int >(s[0].size(), -1));
  queue< pair< int, int > > que;
  for(int i = 0; i < s.size(); i++) {
    for(int j = 0; j < s[i].size(); j++) {
      if(s[i][j] == start) {
        que.emplace(i, j);
        min_cost[i][j] = 0;
      }
    }
  }
  while(!que.empty()) {
    auto p = que.front();
    que.pop();
    for(int i = 0; i < 4; i++) {
      int ny = p.first + vy[i], nx = p.second + vx[i];
      if(nx < 0 || ny < 0 || nx >= s[0].size() || ny >= s.size()) continue;
      if(min_cost[ny][nx] != -1) continue;
      if(wall.find(s[ny][nx]) != string::npos) continue;
      min_cost[ny][nx] = min_cost[p.first][p.second] + 1;
      que.emplace(ny, nx);
    }
  }
  return min_cost;
}

int main() {
  cin>>h>>w>>n;

  vector<string> s(h);
  range(i,0,h){
    cin>>s[i];
  }

  vector<vector<vector<int>>> dist(10);
  dist[0]=grid_bfs(s,'S',"X");
  range(i,1,n){
    char sc=i+'0';
    dist[i]=grid_bfs(s,sc,"X");
  }

  ll ans=0;
  range(i,0,n){
    range(j,0,h){
      range(k,0,w){
        char nextc=(i+1)+'0';
        if(s[j][k]==nextc){
          ans+=dist[i][j][k];
        }
      }
    }
  }
  cout<<ans<<endl;
}