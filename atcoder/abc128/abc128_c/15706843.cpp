// detail: https://atcoder.jp/contests/abc128/submissions/15706843
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;


int main(){
  int N,M;
  cin>>N>>M;
  vector<int> k(M);
  vector<int> p(M);
  vector<vector<int>> s(M,vector<int>(10));
  for(int i=0;i<M;i++){
    cin>>k[i];
    for(int j=0;j<k[i];j++){
      cin>>s[i][j];
      s[i][j]--;
    }
  }
  for(int i=0;i<M;i++){
    cin>>p[i];
  }
  int ans=0;
  for(int i=0;i<(1<<N);i++){
    int cnt=0;
    bitset<10> biti(i);
    //cout<<"biti="<<biti<<endl;
    vector<int> sum(M,0);
    for(int i2=0;i2<M;i2++){
      for(int j2=0;j2<k[i2];j2++){
        if(biti[s[i2][j2]]){
          sum[i2]++;
        }
      }
      //printf("sum%%2=%d p[%d]=%d\n",sum[i2]%2,i2,p[i2]);
      if(sum[i2]%2==p[i2]){
        cnt++;
      }
    }
    if(cnt==M){
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
