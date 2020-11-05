// detail: https://atcoder.jp/contests/code-festival-2016-qualb/submissions/17883998
#include<iostream>
#include<string>
using namespace std;


void Yes(){
  cout<<"Yes\n";
}

void No(){
  cout<<"No\n";
}

int main(){
  int n,a,b;
  string s;
  cin>>n>>a>>b>>s;
  int cnt,bcnt;
  cnt=bcnt=0;
  for(int i=0;i<n;i++){
    if(s[i]=='c'){
      No();
      continue;
    }
    if(s[i]=='b'){
      if(cnt<a+b&&bcnt<b){
        cnt++;
        bcnt++;
        Yes();
        continue;
      }
      No();
      continue;
    }
    if(cnt<a+b){
      Yes();
      cnt++;
      continue;
    }
    No();
  }
  return 0;
}