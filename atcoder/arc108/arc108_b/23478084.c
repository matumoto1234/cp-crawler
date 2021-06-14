// detail: https://atcoder.jp/contests/arc108/submissions/23478084
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  string s;
  cin>>n>>s;
  vector<char> st;
  for(int i=0;i<n;i++){
    if(s[i]=='x' && st.size()>=2 && st.back()=='o' && st[st.size()-2]=='f'){
      st.pop_back();
      st.pop_back();
      continue;
    }
    st.emplace_back(s[i]);
  }
  cout<<st.size()<<endl;
}