// detail: https://atcoder.jp/contests/keyence2020/submissions/15809567
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

struct robo{
  int x,l;
};

bool asc(const robo& left,const robo& right){
  return left.x==right.x?left.l<right.l:left.x<right.x;
}

int main(){
  int ans=0;
  int n;
  cin>>n;
  vector<robo> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i].x>>a[i].l;
  }
  sort(a.begin(),a.end(),asc);

  for(int i=0;i<n-1;i++){
    //printf("%d %d\n", a[i + 1].x - a[i + 1].l + 1, a[i].x + a[i].l - 1);
    if(a[i+1].x-a[i+1].l+1<a[i].x+a[i].l-1){
      if(a[i+1].x+a[i+1].l-1>a[i].x+a[i].l-1){
        a[i+1].x=-INF;
        a[i+1].l=0;
      }else{
        a[i].x=-INF;
        a[i].l=0;
      }
      ans++;
    }
  }
  cout<<n-ans<<endl;
  return 0;
}