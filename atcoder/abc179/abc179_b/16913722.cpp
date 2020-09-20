// detail: https://atcoder.jp/contests/abc179/submissions/16913722
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n;
  cin>>n;
  vector<vector<int>> a(n,vector<int>(2));
  int count=0;
  bool flg=false;
  for(int i=0;i<n;i++){
    cin>>a[i][0]>>a[i][1];
    if(a[i][0]==a[i][1]){
      count++;
    }else{
      count=0;
    }
    if(count>=3){
      flg=true;
      break;
    }
  }
  cout<<(flg?"Yes":"No")<<endl;
  return 0;
}