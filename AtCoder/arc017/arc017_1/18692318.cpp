// detail: https://atcoder.jp/contests/arc017/submissions/18692318
#include<iostream>
using namespace std;

bool isprime(int x){
  for(int i=2;i<x;i++){
    if(x%i==0) return false;
  }
  return true;
}
int main(){
  int x;
  cin>>x;
  cout<<(isprime(x)?"YES":"NO")<<endl;
  return 0;
}