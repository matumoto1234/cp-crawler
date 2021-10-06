// detail: https://atcoder.jp/contests/abc221/submissions/26386008
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  string s;
  cin>>s;
  sort(s.rbegin(),s.rend());
  string front,back;
  back=s;
  
  ll ans=-INT64_MAX;
  for(int i=0;i<(int)s.size();i++){
    front+=s[i];
    back.erase(back.begin());
    ans=max(ans,stoll(front)*stoll(back));
  }
  cout<<ans<<endl;
}