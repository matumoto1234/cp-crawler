// detail: https://atcoder.jp/contests/abc122/submissions/16488617
#include<bits/stdc++.h>
using namespace std;

void outputV(vector<int>);
void outputV(vector<vector<int>>);

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n,q;
  string s;
  cin>>n>>q>>s;
  vector<int> ruiseki(n+1,0);
  for(int i=0;i<n;i++){
    if(s[i]=='A'&&s[i+1]=='C'){
      ruiseki[i+1]++;
    }
    ruiseki[i+1]+=ruiseki[i];
  }
  //outputV(ruiseki);
  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    l--;
    r--;
    cout<<ruiseki[r]-ruiseki[l]<<endl;
  }
  return 0;
}

void outputV(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    if (i) {
      //cout << ' ';
    }
    cout << v[i];
  }
  cout << endl;
}

void outputV(vector<vector<int>> v) {
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      if (j) {
        cout << ' ';
      }
      cout << v[i][j];
    }
    cout << endl;
  }
}