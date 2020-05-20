// detail: https://atcoder.jp/contests/APG4b/submissions/13435830
#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < (n); i++)

int main(){
  vector<int> a(5);
  loop(i, 5){
    cin>>a[i];
  }
  loop(i,4){
    if(a[i]==a[i+1]){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}