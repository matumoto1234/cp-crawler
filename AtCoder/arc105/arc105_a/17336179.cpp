// detail: https://atcoder.jp/contests/arc105/submissions/17336179
#include <bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int a[4];
  int sum=0;
  for(int i=0;i<4;i++){
    cin>>a[i];
    sum+=a[i];
  }
  if(sum%2==0){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}