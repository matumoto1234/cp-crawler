// detail: https://atcoder.jp/contests/abc185/submissions/18767744
#include<bits/stdc++.h>
using namespace std;

//BEGIN CUT HERE
template <typename T>
struct SegmentTree{
  using F = function<T(T,T)>;
  int n;
  F f;
  T ti;
  vector<T> dat;

  SegmentTree(F f,T ti):f(f),ti(ti){}

  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,ti);
  }

  void build(const vector<T> &v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }

  void set_val(int k,T x){
    k+=n;
    dat[k]^=x;
    while(k>>=1)
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);
  }

  T query(int a,int b){
    return dfs(a,b,1,1,n+1);
  }

  T dfs(int a,int b,int k,int l,int r){
    if(r<=a||b<=l) return ti;
    if(a<=l&&r<=b) return dat[k];
    else{
      T vl=dfs(a,b,k*2,l,(l+r)/2);
      T vr=dfs(a,b,k*2+1,(l+r)/2,r);
      return f(vl,vr);
    }
  }
};
//END CUT HERE

int main(){
  int n,q;
  cin>>n>>q;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  auto f=[](int a,int b){return a^b;};
  SegmentTree<int> seg(f,0);
  seg.build(a);

  for(int i=0;i<q;i++){
    int t,x,y;
    cin>>t>>x>>y;
    if(t==1){
      seg.set_val(x-1,y);
      continue;
    }
    cout<<seg.query(x,y+1)<<'\n';
  }
  return 0;
}
