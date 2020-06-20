// detail: https://atcoder.jp/contests/abc115/submissions/14488671
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

ll ans=0;
vector<ll> num(51,1);
vector<ll> p_num(51,1);
ll nibun(ll high,ll low,ll mid,ll cur,ll x){
  if(cur==0){
    //cout<<"aiueo"<<endl;
    return 1;
  }
  if(x==low){
    //cout<<"aaaaa"<<endl;
    return 0;
  }
  if(x==high){
    return p_num[cur];
    //cout<<"bbbbb"<<endl;
  }
  if(x==mid){
    //cout<<"ccccc"<<endl;
    return p_num[cur]/2+1;
  }
  if(mid<x){
    ans+=p_num[cur]/2+1;
    //cout<<high-1<<" "<<mid+1<<" "<<(high+mid)/2<<endl;
    return nibun(high-1,mid+1,(high+mid)/2,cur-1,x);
  }
  else{
    //cout<<mid-1<<" "<<low+1<<" "<<(mid+low)/2<<endl;
    return nibun(mid-1,low+1,(mid+low)/2,cur-1,x);
  }
}
int main(){
  ll n,x;
  cin>>n>>x;
  for(int i=1;i<=n;i++){
    num[i]=num[i-1]*2+3;
    p_num[i]=2*p_num[i-1]+1;
    //cout<<num[i]<<endl<<p_num[i]<<endl;
  }
  ans+=nibun(num[n],1,num[n]/2+1,n,x);
  cout<<ans<<endl;
  return 0;
}
