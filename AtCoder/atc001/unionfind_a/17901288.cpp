// detail: https://atcoder.jp/contests/atc001/submissions/17901288
#include<bits/stdc++.h>
using namespace std;
using ll = long long;


class UnionFind{
public:
  vector<ll> par;
  vector<ll> siz;

  UnionFind(ll sz):par(sz),siz(sz){
    for(ll i=0;i<sz;i++){
      par[i]=i;
    }
  }

  void init(ll sz){
    par.resize(sz);
    siz.assign(sz,1LL);
    for(ll i=0;i<sz;i++){
      par[i]=i;
    }
  }

  ll root(ll x){
    while(par[x]!=x){
      x=par[x]=par[par[x]];
    }
    return x;
  }

  bool merge(ll x,ll y){
    x=root(x);
    y=root(y);
    if(x==y) return false;

    if(siz[x]<siz[y])swap(x,y);
    siz[x]+=siz[y];
    par[y]=x;
    return true;
  }

  bool issame(ll x,ll y){
    return root(x)==root(y);
  }

  ll size(ll x){
    return siz[root(x)];
  }
};

struct zahyo{
  int y,x;
};

bool range_check(int h,int w,int y,int x){
  if(y<0||x<0||y>=h||x>=w){
    return false;
  }
  return true;
}


int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n,q;
  cin>>n>>q;
  UnionFind tree(n);
  for(int i=0;i<q;i++){
    int p,a,b;
    cin>>p>>a>>b;

    if(p==0){
      tree.merge(a,b);
    }else{
      cout<<(tree.issame(a,b)?"Yes\n":"No\n");
    }
  }
  return 0;
}
