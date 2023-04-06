// detail: https://atcoder.jp/contests/agc034/submissions/15257054
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, a, b, c, d;
  bool exchange=false;
  bool rock_cont = false;
  string s;
  cin >> n >> a >> b >> c >> d >> s;
  for (int i = 0; i < n;i++){
    if(i<=n-3&&s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.'){
      if(i>=a-1&&i>=b-1){
        exchange = true;
      }
    }
    if(i<=n-2&&s[i]=='#'&&s[i+1]=='#'){
      rock_cont = true;
    }
  }
  if(rock_cont){
    cout << "No" << endl;
    return 0;
  }
  if(a>b&&c<d){
    if(!exchange){
      cout << "No" << endl;
      return 0;
    }
  }
  if(a<b&&c>d){
    if(!exchange){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}