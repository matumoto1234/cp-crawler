// detail: https://atcoder.jp/contests/abc122/submissions/18698522
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
  int n,q;
  string s;
  cin>>n>>q>>s;

  vector<int> ru(n+1,0);
  for(int i=1;i<n;i++){
    if(s[i]=='C'&&s[i-1]=='A'){
      ru[i+1]++;
    }
    ru[i+1]+=ru[i];
  }

//  for(int x:r){
//    cerr<<x<<' ';
//  }
//  cerr<<endl;

  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    cout<<ru[r]-ru[l]<<'\n';
  }
  return 0;
}