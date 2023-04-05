// detail: https://atcoder.jp/contests/abc177/submissions/16361281
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind {
  vector<int> siz;
  vector<int> par;  // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

  UnionFind(int N) : par(N) {  //最初は全てが根であるとして初期化
    for (int i = 0; i < N; i++){
      par[i] = i;
    }
  }
  void init(int x){
    //par.resize(x);
    siz.assign(x,1);
    for(int i=0;i<x;i++){
      par[i]=i;
    }
  }

  int root(int x) {  // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x)
      return x;
    return par[x] = root(par[x]);
  }

  void unite(int x, int y) {  // xとyの木を併合
    int rx = root(x);         // xの根をrx
    int ry = root(y);         // yの根をry
    if (rx == ry){
      return;  // xとyの根が同じ(=同じ木にある)時はそのまま
    }
    if(siz[rx]<siz[ry]){
      int temp=rx;
      rx=ry;
      ry=temp;
    }
    siz[rx]+=siz[ry];
    //cout<<"rx="<<rx<<" ry="<<ry<<endl;
    //cout<<"siz[rx]="<<siz[rx]<<" siz[ry]="<<siz[ry]<<endl;
    par[ry] = rx;  // xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
  }

  bool same(int x, int y) {  // 2つのデータx, yが属する木が同じならtrueを返す
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }

  int size(int x){
    //cout<<"root(x)="<<root(x)<<endl;
    return siz[root(x)];
  }
};

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n,m;
  cin>>n>>m;
  UnionFind tree(n);
  tree.init(n);
  int a,b;
  for(int i=0;i<m;i++){
    cin>>a>>b;
    a--;
    b--;
    tree.unite(a,b);
  }
  int ans=-1;
  for(int i=0;i<n;i++){
    ans=max(ans,tree.size(i));
    //cout<<tree.siz[i]<<" "<<tree.par[i]<<endl;
  }
  cout<<ans<<endl;
  return 0;
}