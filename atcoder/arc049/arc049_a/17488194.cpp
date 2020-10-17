// detail: https://atcoder.jp/contests/arc049/submissions/17488194
#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int a[4];
  for(int i=0;i<4;i++){
    cin>>a[i];
    s.insert(s.begin()+a[i],'"');
  }
  cout<<s<<endl;
  return 0;
}