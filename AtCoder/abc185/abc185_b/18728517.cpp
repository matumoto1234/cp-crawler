// detail: https://atcoder.jp/contests/abc185/submissions/18728517
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n,m,t;
  cin>>n>>m>>t;
  bool flg=true;
  int last=0;
  int b=n;
  for(int i=0;i<m;i++){
    int l,r;
    cin>>l>>r;
    n-=l-last;
    if(n<=0){
      flg=false;
      break;
    }
    last=r;
    n+=r-l;
    if(n>b){
      n=b;
    }
  }
  n-=t-last;
  if(n<=0){
    flg=false;
  }
  cerr<<n<<endl;
  cout<<(flg?"Yes":"No")<<endl;
  return 0;
}
