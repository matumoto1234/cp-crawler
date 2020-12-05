// detail: https://atcoder.jp/contests/arc110/submissions/18594893
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
//using ll = boost::multiprecision::cpp_int;

ll llpow(ll a,ll e){
  if(e==0){
    return 1LL;
  }
  if(e%2==0){
    ll res=llpow(a,e/2);
    return res*res;
  }else{
    ll res=llpow(a,e-1)*a;
    return res;
  }
}

int main() {
  ll n;
  string t;
  cin >> n>>t;
  string s="110";
  ll counter=1;
  while(s.size()<2*t.size()){
    s+="110";
    counter++;
    if(s.size()>t.size()&&s.find(t,t.size())==string::npos){
      break;
    }
  }
  ll cnt=0;
  ll last=-100100100;
  for(int i=0;i<s.size();i++){
    ll idx=s.find(t,i);
    if(idx!=string::npos&&last!=idx){
      cnt++;
      last=idx;
    }else if(idx==string::npos){
      break;
    }
  }
  //cerr<<cnt<<' '<<last<<endl;
  counter--;
  ll N=llpow(10LL,10LL)-counter;
  //ll N=4-counter;
  ll ans=N*cnt;
  cout<<ans<<endl;
  return 0;
}