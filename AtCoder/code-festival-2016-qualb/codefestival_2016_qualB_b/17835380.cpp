// detail: https://atcoder.jp/contests/code-festival-2016-qualb/submissions/17835380
#include<iostream>
#include<string>
using namespace std;
int main(){
  int n,a,b;
  string s;

  cin>>n>>a>>b>>s;
  int counter=0;
  int bcounter=0;
  for(int i=0;i<n;i++){
    if(s[i]=='c'){
      cout<<"No"<<endl;
      continue;
    }
    if(counter>=a+b){
      cout<<"No"<<endl;
      continue;
    }
    counter++;
    if(s[i]=='b'){
      if(bcounter>=b){
        cout<<"No"<<endl;
        continue;
      }
      bcounter++;
    }
    cout<<"Yes"<<endl;
  }
  return 0;
}