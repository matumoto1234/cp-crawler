// detail: https://atcoder.jp/contests/agc034/submissions/15258042
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, d;
  string s;
  bool exchange = false, rock = false, flg;
  cin >> n >> a >> b >> c >> d >> s;
  for (int i = max(a, b) - 1; i <= min(c, d) - 1 && i < n - 1; i++) {
    if (s[i] == '.') {
      if(i-1>-1){
        if (s[i - 1] == '.' && s[i + 1] == '.') {
          exchange = true;
        }
      }
    }
    if (s[i] == '#') {
      if (s[i + 1] == '#') {
        rock = true;
      }
    }
  }
  if(rock){
    flg = false;
  }
  else if(a>b&&c<d){
    if(exchange==false){
      flg = false;
    }
  }
  else if(a<b&&c>d){
    if(exchange==false){
      flg = false;
    }
  }
  else{
    flg = true;
  }
  if(flg){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}

/*#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, a, b, c, d;
  bool exchange=false;
  bool rock_conti = false;
  string s;
  cin >> n >> a >> b >> c >> d >> s;
  for (int i = 0; i < n;i++){
    cout << exchange << endl;
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
}*/