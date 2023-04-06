// detail: https://atcoder.jp/contests/abc185/submissions/18764151
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAXN = (1LL<<17);
const ll INF = 100100100100LL;

ll n;
vector<ll> dat(2*MAXN-1,0LL);

void init(ll n_){
  n=1;
  while(n<n_) n*=2;

  for(ll i=0;i<2*n-1;i++){
    dat[i]=0LL;
  }
}

void update(ll k,ll a){
  k+=n-1;
  dat[k]^=a;
  a=dat[k];
  while(k>0){
    k=(k-1)/2;
    int l=k*2+1;
    int r=k*2+2;
    dat[k]=dat[l]^dat[r];
  }
}

void init_update(ll k,ll a){
  k+=n-1;
  while(k>0){
    k=(k-1)/2;
    dat[k]^=a;
  }
}

ll query(int a,int b,int k,int l,int r){
  if(r<=a||b<=l) return 0;
  if(a<=l&&r<=b) return dat[k];
  else{
    int vl=query(a,b,k*2+1,l,(l+r)/2);
    int vr=query(a,b,k*2+2,(l+r)/2,r);
    return vl^vr;
  }
}


int main(){
  ll q;
  cin>>n>>q;
  ll nn=n;
  init(n);
  for(int i=0;i<nn;i++){
    cin>>dat[i+n-1];
    init_update(i,dat[i+n-1]);
  }
  
  for(int i=0;i<2*n-1;i++){
    cerr<<dat[i]<<' ';
  }
  cerr<<'\n';
  cerr<<"n:"<<n<<endl;
  for(int i=0;i<q;i++){
    ll t,x,y;
    cin>>t>>x>>y;
    x--;
    if(t==1){
      update(x,y);
      continue;
    }
    cout<<query(x,y,0,0,n)<<'\n';
  }
  return 0;
}
