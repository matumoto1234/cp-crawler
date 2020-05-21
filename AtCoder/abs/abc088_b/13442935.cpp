// detail: https://atcoder.jp/contests/abs/submissions/13442935
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b;
  cin >> n;
  vector<int> data(n);
  for(int i=0;i<n;i++){
    cin>>data[i];
  }
  sort(data.begin(),data.end(),greater<int>());
  a=b=0;
  for(int i=0;i<n;i++){
    i%2==0?a+=data[i]:b+=data[i];
  }
  cout<<a-b<<endl;
  return 0;
}