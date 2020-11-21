// detail: https://atcoder.jp/contests/arc108/submissions/18260141
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include<stack>
using namespace std;
using ll = long long;

int main() {
  ll n;
  string s;
  cin >> n>>s;
  stack<char> st;
  ll cnt=0;
  for(int i=0;i<n;i++){
    if(s[i]=='x'){
      if(st.empty()){
        continue;
      }
      char a=st.top();
      st.pop();
      if(st.empty()){
        continue;
      }
      char b=st.top();
      st.pop();

      if(a=='o'&&b=='f'){
        cnt+=3;
      }else{
        st.push(b);
        st.push(a);
      }
    }else{
      st.push(s[i]);
    }
  }
  cout<<n-cnt<<endl;
  return 0;
}