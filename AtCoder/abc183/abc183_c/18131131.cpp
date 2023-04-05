// detail: https://atcoder.jp/contests/abc183/submissions/18131131
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  ll n,k;
  cin >> n>>k;
  vector<vector<ll>> G(n,vector<ll>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>G[i][j];
    }
  }
  vector<int> index(n-1);
  for(int i=0;i<n-1;i++){
    index[i]=i+1;
  }
  ll counter=0;
  do{
    ll sum=0;
    for(int i=0;i<n-1;i++){
      //cout<<index[i]<<' ';
      if(i==0){
        sum+=G[0][index[i]];
      }
      if(i==n-2){
        sum+=G[index[i]][0];
        continue;
      }
      sum+=G[index[i]][index[i+1]];
    }
    //cout<<sum<<endl;
    if(sum==k){
      counter++;
    }
  }while(next_permutation(index.begin(),index.end()));
  cout<<counter<<endl;
  return 0;
}