// detail: https://atcoder.jp/contests/dp/submissions/18403949
#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
const int MAXN=100;
const int MAXW=100000;

int N,W;
int w[MAXN];
ll v[MAXN];

vector<ll> done(MAXW+1,-1);
ll calc(int weight,vector<bool>& flg){
  if(weight==0){
    return 0;
  }

  ll &maxv=done[weight];
  if(maxv!=-1){
    return maxv;
  }

  for(int i=0;i<N;i++){
    if(flg[i]) continue;
    if(weight-w[i]>=0){
      flg[i]=true;
      maxv=max(maxv,calc(weight-w[i],flg)+v[i]);
      flg[i]=false;
    }
  }
  return maxv;
}

int main(){
  cin>>N>>W;
  for(int i=0;i<N;i++){
    cin>>w[i]>>v[i];
  }
  vector<bool> flg(N,false);
  cout<<calc(W,flg)<<endl;
  
  return 0;
}