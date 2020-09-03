// detail: https://atcoder.jp/contests/abc084/submissions/16487557
#include<bits/stdc++.h>
const int MAX = 1e5;
using namespace std;

bool isPrime(int);
void outputV(vector<int>);
void outputV(vector<vector<int>>);

int main(){
  vector<int> ruiseki(MAX+1,0);
  for(int i=3;i<MAX;i+=2){
    if(isPrime(i)&&isPrime((i+1)/2)){
      ruiseki[i]++;
    }
    ruiseki[i+1]+=ruiseki[i];
    ruiseki[i+2]+=ruiseki[i];
  }
  //outputV(ruiseki);

  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    cout<<ruiseki[r]-ruiseki[l-1]<<endl;
  }
  return 0;
}

bool isPrime(int x){
  if(x<2){
    return false;
  }
  for(int i=2;i*i<=x;i++){
    if(x%i==0){
      return false;
    }
  }
  return true;
}

void outputV(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    if (i) {
      cout << ' ';
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