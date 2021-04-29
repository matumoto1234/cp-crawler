// detail: https://atcoder.jp/contests/code-festival-2017-qualc/submissions/22157699
#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  
  vector<int> cnt(26,0);
  for(char c:s){
    int idx=c-'a';
    cnt[idx]++;
  }
  
  int odd_cnt=0;
  for(int i=0;i<26;i++){
    if(i!='x'-'a' && cnt[i]%2){
      odd_cnt++;
    }
  }
  if(odd_cnt>=2){
    cout<<-1<<endl;
    return 0;
  }
  
  int mid;
  for(int i=0;i<(int)s.size();i++){
    int idx=s[i]-'a';
    if(cnt[idx]%2){
      mid=i;
      break;
    }
  }
  
  bool impo=false;
  vector<int> fcnt(26,0),bcnt(26,0);
  for(int i=0;i<mid;i++) fcnt[s[i]-'a']++;
  for(int i=mid+1;i<(int)s.size();i++) bcnt[s[i]-'a']++;
  for(int i=0;i<26;i++){
    if(i=='x'-'a') continue;
    if(fcnt[i]!=bcnt[i]) impo=true;
  }
  if(impo){
    cout<<-1<<endl;
    return 0;
  }
  if(mid==0){
    cout<<s.size()-1<<endl;
    return 0;
  }
  
  int ans=0;
  int ri=mid+1;
  for(int li=mid-1;li>=0;li--){
    if(s[li]=='x'){
      ans++;
      continue;
    }
    // cerr<<ri<<endl;
    while(ri<(int)s.size() && s[li]!=s[ri]){
      ri++;
      ans++;
    }
  }
  cout<<ans<<endl;
}