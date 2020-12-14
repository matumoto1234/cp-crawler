// detail: https://atcoder.jp/contests/abc185/submissions/18785494
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int ti = 0;

// 1-indexed
vector<int> dat;
int n;

void init(int n_){
  n=1;
  while(n<n_) n*=2;

  dat.assign(2*n,ti);
}

void set_val(int k,int x){
  k+=n;
  dat[k]^=x;
  k/=2;
  while(k>0){
    int l=2*k;
    int r=2*k+1;
    dat[k]=dat[l]^dat[r];
    k/=2;
  }
}

// [a,[l,r),b)
// [l,r)[a,b)[l,r)
// lとrを動かす
int query(int a,int b,int k,int l,int r){
  //cerr<<"a:"<<a<<" b:"<<b<<" k:"<<k<<" l:"<<l<<" r:"<<r<<endl;
  if(r<=a||b<=l) return ti;
  if(a<=l&&r<=b) return dat[k];

  int v1=query(a,b,2*k,l,(l+r)/2);
  int v2=query(a,b,2*k+1,(l+r)/2,r);
  return v1^v2;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int q;
  cin>>n>>q;
  int cpn=n;
  init(n);
  for(int i=0;i<cpn;i++){
    int v;
    cin>>v;
    set_val(i+1,v);
  }
  for(int i=0;i<q;i++){
    int t,x,y;
    cin>>t>>x>>y;
    if(t==1){
      set_val(x,y);
      continue;
    }
    cout<<query(x,y+1,1,1,n)<<'\n';
  }
  return 0;
}