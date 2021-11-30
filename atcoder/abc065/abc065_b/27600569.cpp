// detail: https://atcoder.jp/contests/abc065/submissions/27600569
#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n,cnt=0;
  cin >> n;
  vector<long long> A(n+1),B(n+1);
  for(int i=1;i<=n;i++){
    cin >> A[i];
  }
  B[1]=1;
  for(int i=1;i<=n;i++){
    if(B[i]){
      B[i]=0;
      B[A[i]]=1;
      cnt++;
    }
    if(B[2]){
      cout << cnt <<endl;
      return 0;
    }
  }
  cout << "-1"<<endl;
}