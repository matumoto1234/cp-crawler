// detail: https://atcoder.jp/contests/agc048/submissions/17519790
#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int t;
  cin>>t;
  string atcoder="atcoder";
  for(int i=0;i<t;i++){
    string s;
    cin>>s;
    if(s.size()<atcoder.size()){
      cout<<-1<<"\n";
      continue;
    }
    bool flg=false;
    int counter=0;
    for(int j=0;j<s.size();j++){
      if(s[j]!='a'){
        flg=true;
        break;
      }
      counter++;
    }
    cout<<(flg?counter?1:0:-1)<<'\n';
  }
  return 0;
}