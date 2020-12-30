// detail: https://atcoder.jp/contests/agc039/submissions/19066229
#include<iostream>
#include<vector>
#include<string>
using ll = long long;
using namespace std;

void solve1(string& s,ll k){
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
}

void solve2(string& s,ll k){
  int n=(int)s.size();

  // step1
  ll cnt1=0;
  for(int i=1;i<n;i++){
    if(s[i]==s[i-1]){
      s[i]='A';
      cnt1++;
    }
  }

  // step2
  ll cnt2=cnt1;
  if(s[0]==s[n-1]&&s[0]!='A'){
    s[1]='B';
    cnt2--;
    s[0]='A';
    cnt2++;
    if(s[n-2]!='B'){
      s[n-2]='B';
      cnt2--;
    }
    s[n-1]='A';
    cnt2++;
  }

  ll ans=cnt1*((k+1)/2)+cnt2*(k/2);
  cout<<ans<<endl;
}

int main(){
  string s;
  ll k;
  cin>>s>>k;
  int n=(int)s.size();
  if(n%2==0){
    solve1(s,k);
  }else{
    solve2(s,k);
  }
  return 0;
}