// detail: https://atcoder.jp/contests/abc237/submissions/28902185
#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n;
  cin>>n;
  
  cout<<(-(1LL<<31) <= n and n < (1LL<<31)?"Yes":"No")<<endl;
}