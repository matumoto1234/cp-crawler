// detail: https://atcoder.jp/contests/abc089/submissions/16424541
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct zahyo{
  ll y,x;
};

ll absll(ll x){
  if(x<0){
    return -1*x;
  }
  return x;
}

void output(vector<vector<ll>> v){
  cout<<"output---------"<<endl;
  for(ll i=0;i<v.size();i++){
    for(ll j=0;j<v[i].size();j++){
      if(j){
        cout<<' ';
      }
      cout<<v[i][j];
    }
    cout<<endl;
  }
  cout<<"ouput---------"<<endl;
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll h,w,d;
  cin>>h>>w>>d;
  map<ll,zahyo> m;
  zahyo xy;
  vector<vector<ll>> a(h,vector<ll> (w));
  ll maxv=-1;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      cin>>a[i-1][j-1];
      maxv=max(maxv,a[i-1][j-1]);
      xy.y=i;
      xy.x=j;
      m[a[i-1][j-1]]=xy;
    }
  }
  vector<vector<ll>> cost(h*w);
  ll costi=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      ll now,next,last=0;
      now=a[i][j];
      next=a[i][j]+d;
      while(maxv>=now){
        cost[costi].push_back(last+absll(m[next].y-m[now].y)+absll(m[next].x-m[now].x));
        last = last + absll(m[next].y - m[now].y) + absll(m[next].x - m[now].x);
        now+=d;
        next+=d;
      }
      costi++;
    }
  }
  //output(cost);
  ll q;
  cin>>q;
  ll l,r;
  for(ll i=0;i<q;i++){
    cin>>l>>r;
    if(l==r){
      cout<<0<<endl;
      continue;
    }
    cout<<cost[(m[l].y-1)*w+m[l].x-1][(r-l)/d-1]<<endl;
  }
  return 0;
}