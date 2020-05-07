// detail: https://atcoder.jp/contests/joi2020yo1a/submissions/12920648
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,cnt=0;
  string s;
  cin>>n>>s;
  for(int i=0;i<n;i++){
    switch(s[i]){
      case 'a':
        cnt++;
        break;
      case 'i':
        cnt++;
        break;
      case 'u':
        cnt++;
        break;
      case 'e':
        cnt++;
        break;
      case 'o':
        cnt++;
        break;
      default:
        break;
    }
  }
  cout<<cnt<<endl;
}
