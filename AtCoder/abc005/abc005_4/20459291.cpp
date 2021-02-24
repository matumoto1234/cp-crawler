// detail: https://atcoder.jp/contests/abc005/submissions/20459291
#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T1, typename T2> ostream &operator<<(ostream &os,const pair<T1,T2> &p) { os<<p.first<<' '<<p.second<<'\n'; return os;}
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ll = long long;
using PL = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

template< typename T >
struct SparseTable {
  vector< vector< T > > st;
  vector< int > lookup;

  SparseTable(const vector< T > &v) {
    int b = 0;
    while((1 << b) <= v.size()) ++b;
    st.assign(b, vector< T >(1 << b));
    for(int i = 0; i < v.size(); i++) {
      st[0][i] = v[i];
    }
    for(int i = 1; i < b; i++) {
      for(int j = 0; j + (1 << i) <= (1 << b); j++) {
        st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
    lookup.resize(v.size() + 1);
    for(int i = 2; i < lookup.size(); i++) {
      lookup[i] = lookup[i >> 1] + 1;
    }
  }

  inline T rmq(int l, int r) {
    int b = lookup[r - l];
    return max(st[b][l], st[b][r - (1 << b)]);
  }
};

template <class T>
struct Cumlative{
  vector<vector<T>> data;
  Cumlative(int H,int W):data(H+1,vector<T>(W+1,0)){}

  void set(int y,int x,int v){
    y++;
    x++;
    if(y>=data.size()||x>=data[0].size()) return;
    data[y][x]+=v;
  }

  void build(){
    for(int i=1;i<data.size();i++){
      for(int j=1;j<data[i].size();j++){
        data[i][j]+=data[i][j-1]+data[i-1][j]-data[i-1][j-1];
      }
    }
  }

  // [ (sy,sx), (gy,gx) )
  T query(int sy,int sx,int gy,int gx){
    return data[gy][gx]-data[gy][sx]-data[sy][gx]+data[sy][sx];
  }
};

int main() {
  int n;
  cin>>n;
  
  Cumlative<ll> d(n,n);
  range(i,0,n){
    range(j,0,n){
      int D;
      cin>>D;
      d.set(i,j,D);
    }
  }

  d.build();

  vector<ll> maxv(n*n+1,0);
  range(i,0,n) range(j,0,n){
    range(k,i,n) range(l,j,n){
      int s=(k-i+1)*(l-j+1);
      chmax(maxv[s],d.query(i,j,k+1,l+1));
    }
  }

  SparseTable<ll> st(maxv);

  int q;
  cin>>q;
  range(i,0,q){
    int p;
    cin>>p;
    cout<<st.rmq(0,p+1)<<newl;
  }
}