// detail: https://atcoder.jp/contests/abc173/submissions/17358613
#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,k;
  cin>>h>>w>>k;
  vector<string> s(h);
  for(int i=0;i<h;i++){
    cin>>s[i];
  }
  int bsum=0;
  vector<int> g(h,0),r(w,0);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]=='#'){
        g[i]++;
        r[j]++;
        bsum++;
      }
    }
  }

  int ans=0;
  for(int i=0;i<(1<<h);i++){
    bitset<6> gyou(i);
    for(int j=0;j<(1<<w);j++){
      bitset<6> retsu(j);
      int sum=0;

      for(int l=0;l<h;l++){
        if(gyou[l]) sum+=g[l];
      }
      for(int l=0;l<w;l++){
        if(retsu[l]) sum+=r[l];
      }
      for(int i2=0;i2<h;i2++){
        for(int j2=0;j2<w;j2++){
          if(s[i2][j2]=='#'&&gyou[i2]&&retsu[j2]) sum--;
        }
      }

      if(bsum-sum==k){
        ans++;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}