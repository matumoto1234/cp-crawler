// detail: https://atcoder.jp/contests/abc124/submissions/19085043
#include<bits/stdc++.h>
using namespace std;

struct section{
  char c;
  int l;
  section(){}
  section(char c,int l):c(c),l(l){}
};

int main(){
  int n,k;
  string s;
  cin>>n>>k>>s;
  vector<section> t;
  int cnt=1;
  for(int i=1;i<n;i++){
    if(s[i-1]==s[i]){
      cnt++;
    }else{
      t.emplace_back(s[i-1],cnt);
      cnt=1;
    }
  }
  t.emplace_back(s[n-1],cnt);

  int sz=(int)t.size();
  int maxsum=-1;
  int idx=-1;
  for(int i=0;i<sz;i++){
    if(t[i].c=='0'){
      int temp=0;
      if(i-1>=0){
        temp+=t[i-1].l;
      }
      temp+=t[i].l;
      if(i+1<=sz-1){
        temp+=t[i+1].l;
      }

      if(maxsum<temp){
        maxsum=temp;
        idx=i;
      }
    }
  }
  if(idx==-1){
    cout<<n<<endl;
    return 0;
  }

  t[idx].c='1';
  if(idx-1>=0){
    t[idx].l+=t[idx-1].l;
    t.erase(t.begin()+idx-1);
    idx--;
  }
  if(idx+1<=n-1){
    t[idx].l+=t[idx+1].l;
    t.erase(t.begin()+idx+1);
  }
  sz=(int)t.size();
  k--;
  int ans=t[idx].l;
  int left=idx-1,right=idx+1;
  while(k){
    if(left>=0&&t[left].c=='1'){
      ans+=t[left].l;
      left--;
    }
    if(right<=sz-1&&t[right].c=='1'){
      ans+=t[right].l;
      right++;
    }
    if(left<0){
      if(right>=sz){
        break;
      }
      ans+=t[right].l;
      t[right].c='1';
      right++;
      k--;
      continue;
    }
    if(right>=sz){
      if(left<0){
        break;
      }
      ans+=t[left].l;
      t[left].c='1';
      left--;
      k--;
      continue;
    }
    if(t[left].l>t[right].l){
      ans+=t[left].l;
      t[left].c='1';
      left--;
      k--;
    }else{
      ans+=t[right].l;
      t[right].c='1';
      right++;
      k--;
    }
  }
  if(left>=0&&t[left].c=='1'){
    ans+=t[left].l;
    left--;
  }
  if(right<=sz-1&&t[right].c=='1'){
    ans+=t[right].l;
    right++;
  }
//  for(int i=0;i<sz;i++){
//    cout<<"c:"<<t[i].c<<" l:"<<t[i].l;
//    if(i==left) cout<<" left";
//    if(i==right) cout<<" right";
//    if(i==idx) cout<<" idx";
//    cout<<endl;
//  }
  cout<<ans<<endl;
}