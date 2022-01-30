// detail: https://atcoder.jp/contests/abc237/submissions/28901556
#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n;
  cin>>n;
  
  cout<<(-(1<<31) <= n and n < (1<<31)?"Yes":"No")<<endl;
}