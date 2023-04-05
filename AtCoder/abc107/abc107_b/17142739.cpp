// detail: https://atcoder.jp/contests/abc107/submissions/17142739
#include<bits/stdc++.h>
using namespace std;

void outstr(vector<string> s){
  //cout<<"------------"<<endl;
  for(int i=0;i<s.size();i++){
    cout<<s[i]+"\n";
  }
}

vector<string> del_str(vector<string> s,int h,int w){
  vector<string> ret;
  for(int i=0;i<h;i++){
    bool flg=false;
    for(int j=0;j<w;j++){
      if(s[i][j]=='#'){
        flg=true;
        break;
      }
    }
    if(flg){
      ret.push_back(s[i]);
    }
  }
  return ret;
}


int main(){
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  for(int i=0;i<h;i++){
    cin>>s[i];
  }
  vector<string> temp=del_str(s,h,w);
  h=temp.size();
  vector<string> temp2(w);
  for(int i=0;i<w;i++){
    for(int j=0;j<h;j++){
      temp2[i].push_back(temp[j][w-i-1]);
    }
  }
  vector<string> temp3=del_str(temp2,w,h);
  //outstr(temp3);
  w=temp3.size();
  vector<string> ans(h);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      ans[i].push_back(temp3[w-j-1][i]);
    }
  }
  outstr(ans);
  return 0;
}