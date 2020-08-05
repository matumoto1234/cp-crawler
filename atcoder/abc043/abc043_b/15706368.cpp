// detail: https://atcoder.jp/contests/abc043/submissions/15706368
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;


int main(){
  string s;
  cin>>s;
  string ans;
  for(int i=0;i<s.size();i++){
    if(s[i]=='B'){
      if(!ans.empty()){
        ans.erase(ans.end()-1);
      }
    }else{
      ans.push_back(s[i]);
    }
    //cout<<ans<<endl;
  }
  cout<<ans<<endl;
  return 0;
}
