// detail: https://atcoder.jp/contests/abc185/submissions/18785284
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const long long MAXN = 300000;
const long long ti = 0;

// 1-indexed
vector<long long> dat;
long long n;

void init(long long n_){
  n=1;
  while(n<n_) n*=2;

  dat.assign(2*n,ti);
}

void set_val(long long k,long long x){
  k+=n;
  dat[k]^=x;
  k/=2;
  while(k>0){
    long long l=2*k;
    long long r=2*k+1;
    dat[k]=dat[l]^dat[r];
    k/=2;
  }
}

// [a,[l,r),b)
// [l,r)[a,b)[l,r)
// lとrを動かす
long long query(long long a,long long b,long long k,long long l,long long r){
  //cerr<<"a:"<<a<<" b:"<<b<<" k:"<<k<<" l:"<<l<<" r:"<<r<<endl;
  if(a<=l&&r<=b) return dat[k];
  if(r<=a||b<=l) return ti;

  long long v1=query(a,b,2*k,l,(l+r)/2);
  long long v2=query(a,b,2*k+1,(l+r)/2,r);
  return v1^v2;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  long long q;
  cin>>n>>q;
  long long cpn=n;
  init(n);
  for(long long i=0;i<cpn;i++){
    long long v;
    cin>>v;
    set_val(i+1,v);
  }
  for(long long i=0;i<q;i++){
    long long t,x,y;
    cin>>t>>x>>y;
    if(t==1){
      set_val(x,y);
      continue;
    }
    cout<<query(x,y+1,1,1,n)<<'\n';
  }
  return 0;
}