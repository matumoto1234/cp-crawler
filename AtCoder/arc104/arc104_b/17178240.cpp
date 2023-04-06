// detail: https://atcoder.jp/contests/arc104/submissions/17178240
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin>>n>>s;

  int ans=0;
  for(int i=0;i<n;i++){
    int c1=0,c2=0;
    for(int j=i;j<n;j++){
      if(s[j]=='A'){
        c1++;
      }else if(s[j]=='T'){
        c1--;
      }else if(s[j]=='C'){
        c2++;
      }else{
        c2--;
      }
      if(c1==0&&c2==0){
        ans++;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}