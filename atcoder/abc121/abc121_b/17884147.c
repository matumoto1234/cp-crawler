// detail: https://atcoder.jp/contests/abc121/submissions/17884147
#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n,m,c;
  cin>>n>>m>>c;
  vector<int> b(m);
  for(int i=0;i<m;i++){
    cin>>b[i];
  }
  vector<vector<int>> a(n,vector<int>(m));
  int ans=0;
  for(int i=0;i<n;i++){
    int sum=0;
    for(int j=0;j<m;j++){
      cin>>a[i][j];
      sum+=a[i][j]*b[j];
    }
    sum+=c;
    if(sum>0){
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}