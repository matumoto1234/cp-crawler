// detail: https://atcoder.jp/contests/joi2020yo1a/submissions/12913257
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  vector<int> cnt(5,0);
  string s;
  cin>>n>>s;
  for(int i=0;i<n;i++){
  	if(s[i]>='a'&&s[i]<='e'){
      cnt[s[i]-'a']++;
    }
  }
  for(auto x:cnt)cout<<x<<endl;
}
