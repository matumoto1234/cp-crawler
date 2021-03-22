// detail: https://atcoder.jp/contests/abc196/submissions/21166025
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

int h,w,a,b,ans=0;
vector<vector<bool>> table;

P pos_to_yx(int pos){ return P(pos/w,pos%w); }
int yx_to_pos(int y,int x){ return y*h+x; }

int is_valid(){
  range(i,0,h) range(j,0,w){
    if(!table[i][j]) return 0;
  }
  return 1;
}

void debug(int pos){
  cerr<<"-----begin-----"<<newl;
  cerr<<"pos:"<<pos<<newl;
  range(i,0,h){
    cerr<<table[i]<<newl;
  }
  cerr<<"------end------"<<newl;
}

void dfs(int pos,int cnta,int cntb){
  auto [y,x]=pos_to_yx(pos);
  //debug(pos);
  if(y==h-1&&x==w-1){
    //if(!table[y][x]&&b>0) table[y][x]=true;
    //ans+=is_valid();
    ans++;
    return;
  }

  if(table[y][x]) dfs(pos+1,cnta,cntb);

  if(cntb+1<=b && !table[y][x]){
    table[y][x]=true;
    dfs(pos+1,cnta,cntb+1);
    table[y][x]=false;
  }

  if(x+1<w && cnta+1<=a && !table[y][x] && !table[y][x+1]){
    table[y][x]=true;
    table[y][x+1]=true;
    dfs(pos+1,cnta+1,cntb);
    table[y][x]=false;
    table[y][x+1]=false;
  }

  if(y+1<h && cnta+1<=a && !table[y][x] && !table[y+1][x]){
    table[y][x]=true;
    table[y+1][x]=true;
    dfs(pos+1,cnta+1,cntb);
    table[y][x]=false;
    table[y+1][x]=false;
  }
}

int main() {
  cin>>h>>w>>a>>b;
  table.assign(h,vector<bool>(w,false));
  dfs(0,0,0);
  cout<<ans<<endl;
}