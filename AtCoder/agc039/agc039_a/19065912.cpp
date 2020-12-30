// detail: https://atcoder.jp/contests/agc039/submissions/19065912
#include<iostream>
#include<vector>
#include<string>
using ll = long long;
using namespace std;
int main(){
  string s;
  ll k;
  cin>>s>>k;
  int n=(int)s.size();
  
  // step1
  ll cnt1=0;
  for(int i=1;i<n;i++){
    if(s[i]==s[i-1]){
      if(i==1){
        s[0]='A';
        cnt1++;
        continue;
      }
      if(i==n-1){
        s[n-1]='A';
        cnt1++;
        continue;
      }
      s[i]='A';
      cnt1++;
    }
  }

  // step2
  ll cnt2=0;
  if(s[0]==s[n-1]&&s[0]!='A'){
    cnt2++;
  }

  // output
  ll ans=cnt1*k+cnt2*(k-1);
  cout<<ans<<endl;
  return 0;
}