// detail: https://atcoder.jp/contests/abc185/submissions/18762823
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAXN = (1LL<<17);
const ll INF = 100100100100LL;

ll n;
vector<ll> data(2*MAXN-1,0LL);

void init(ll n_){
  n=1;
  while(n<n_) n*=2;

  for(ll i=0;i<2*n-1;i++){
    data[i]=0LL;
  }
}

void update(ll k,ll a){
  k+=n-1;
  data[k]^=a;
  ll a=data[k];
  while(k>0){
    k=(k-1)/2;
    data[k]^=a;
  }
}

void init_update(ll k,ll a){
  k+=n-1;
  while(k>0){
    k=(k-1)/2;
    data[k]^=a;
  }
}

ll query(int a,int b,int k,int l,int r){
  if(r<=a||b<=l) return 0;
  if(a<=l&&r<=b) return data[k];
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
    cin>>data[i+n-1];
    init_update(i,data[i+n-1]);
  }
  
  for(int i=0;i<2*n-1;i++){
    cerr<<data[i]<<' ';
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
    y--;
    cout<<query(x,y,0,0,n)<<'\n';
  }
  return 0;
}
