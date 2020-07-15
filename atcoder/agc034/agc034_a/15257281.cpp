// detail: https://atcoder.jp/contests/agc034/submissions/15257281
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, a, b, c, d;
  bool exchange=false;
  bool rock_conti = false;
  string s;
  cin >> n >> a >> b >> c >> d >> s;
  for (int i = 0; i < n;i++){
    if(i<=n-3&&s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.'){
      if(i>=min(a-1,b-1)&&i<min(c-1,d-1)){
        if(i==min(a-1,b-1)){
          if(abs(a-b)==1){
            exchange = true;
          }
        }else{
          exchange = true;
        }
      }
    }
    if(i<=n-2&&s[i]=='#'&&s[i+1]=='#'){
      if(i>min(a-1,b-1)&&i<min(c-1,d-1)){
        rock_conti = true;
      }
    }
  }
  if(rock_conti){
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