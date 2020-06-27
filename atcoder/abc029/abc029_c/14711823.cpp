// detail: https://atcoder.jp/contests/abc029/submissions/14711823
#include<bits/stdc++.h>
using namespace std;
int N;

void dfs(int n, string s){
  if(n==N){
    cout << s << endl;
  }else{
    for (char C = 'a'; C <= 'c';C++){
      dfs(n + 1, s + C);
    }
  }
  return;
}

int main(){
  cin >> N;
  dfs(0, "");
  return 0;
}