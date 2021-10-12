// detail: https://atcoder.jp/contests/abs/submissions/26516680
#include<bits/stdc++.h>
using namespace std;

vector<string> words = {"dream", "dreamer", "erase", "eraser"};
string s;
bool ans=false;

void dfs(int idx){
  if(idx == s.size()){
    ans=true;
    return;
  }
  
  for(int i=0;i<4;i++){
    string word = words[i];
    if(idx + word.size() <= s.size() && s.substr(idx,word.size()) == word){
      dfs(idx + word.size());
    }
  }
}

int main(){
  cin>>s;
  dfs(0);
  
  cout << (ans ? "YES" : "NO") << endl;
}