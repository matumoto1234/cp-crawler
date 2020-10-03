// detail: https://atcoder.jp/contests/arc104/submissions/17165341
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isTrue(char l,char r){
  if(l>r){
    char c=l;
    l=r;
    r=c;
  }
  if(l=='A'&&r=='T'){
    return true;
  }else if(l=='C'&&r=='G'){
    return true;
  }
  return false;
}

void solve(ll& ans,vector<bool> v,string s,int l,int r){
  if(l<0||r>=v.size()){
    return;
  }
  if(v[l]||v[r]){
    return;
  }
  if(isTrue(s[l],s[r])==false){
    return;
  }
  ans++;
  v[l]=true;
  v[r]=true;
  solve(ans,v,s,l-1,r+1);
}

int main() {
  int n;
  string s;
  cin>>n>>s;

  vector<bool> list(n,false);
  ll ans=0;
  int index_before=0,index_after=0;
  for(int i=0;i<n;i++){
    solve(ans,list,s,i,i+1);
  }
  cout<<ans<<endl;
  return 0;
}