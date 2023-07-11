// detail: https://atcoder.jp/contests/abc285/submissions/43484787
#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  
  string s;
  cin>>s;
  
  for(int i=0;i<n;i++) {
    int ans=0;
    for(int l=1;l<n;l++) {
      if(s[l]==s[l+i]){
        ans=l-1;
        break;
      }
    }
    cout<<ans<<endl;
  }
}