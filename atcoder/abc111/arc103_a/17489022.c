// detail: https://atcoder.jp/contests/abc111/submissions/17489022
#include<bits/stdc++.h>
using namespace std;

struct elem{
  int val,cnt;
};

bool asc(const elem& l,const elem& r){
  return l.cnt==r.cnt?l.val<r.val:l.cnt<r.cnt;
}

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  elem init;
  init.val=0;
  init.cnt=0;
  vector<elem> maxv1(1e5+1,init);
  vector<elem> maxv2(1e5+1,init);
  for(int i=0;i<n;i+=2){
    maxv1[a[i]].cnt++;
    maxv1[a[i]].val=a[i];
  }
  for(int i=1;i<n;i+=2){
    maxv2[a[i]].cnt++;
    maxv2[a[i]].val=a[i];
  }
  sort(maxv1.rbegin(),maxv1.rend(),asc);
  sort(maxv2.rbegin(),maxv2.rend(),asc);
  int ans=0;
  if(maxv1[0].val==maxv2[0].val){
    if(maxv1[0].cnt>maxv2[0].cnt){
      ans=maxv1[0].cnt;
      ans+=maxv2[1].cnt;
    }else{
      ans=maxv2[0].cnt;
      ans+=maxv1[1].cnt;
    }
  }else{
    ans=maxv1[0].cnt+maxv2[0].cnt;
  }
  cout<<n-ans<<endl;
  return 0;
}