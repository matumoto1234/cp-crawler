// detail: https://atcoder.jp/contests/arc109/submissions/18471828
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

char battle(char c1,char c2){
  if(c1=='R'){
    if(c2=='S'){
      return c1;
    }
    if(c2=='R'){
      return c1;
    }
    if(c2=='P'){
      return c2;
    }
  }
  if(c1=='P'){
    if(c2=='S'){
      return c2;
    }
    if(c2=='R'){
      return c1;
    }
    if(c2=='P'){
      return c1;
    }
  }
  if(c1=='S'){
    if(c2=='S'){
      return c1;
    }
    if(c2=='R'){
      return c1;
    }
    if(c2=='P'){
      return c2;
    }
  }
  return c2;
}

char dfs(string& s){
  if(s.size()==1){
    return s[0];
  }
  int half=(int)s.size()/2;
  string l=s.substr(0,half);
  if(s.size()%2) half++;
  string r=s.substr(s.size()/2,half);
  return battle(dfs(l),dfs(r));
}

int main() {
  ll n,k;
  cin>>n>>k;
  string s,t;
  cin>>s;
  t.assign(n,'a');
  for(int i=1;i<n;i++){
    t[i-1]=s[i];
  }
  t[n-1]=s[0];

  if(n<k){
    int i;
    for(i=n;i<k;i+=n){
      s+=s;
      t+=t;
    }
    i-=n;
    int j=0;
    while(i<k){
      s+=s[j];
      t+=t[j];
      i++;
      j++;
    }
  }
  vector<char> K(2);
  K[0]=dfs(s);
  if(n%2){
    K[1]=dfs(t);
    cout<<battle(K[0],K[1])<<endl;
  }else{
    cout<<K[0]<<endl;
  }

  return 0;
}