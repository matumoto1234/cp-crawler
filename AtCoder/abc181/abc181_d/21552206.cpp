// detail: https://atcoder.jp/contests/abc181/submissions/21552206
#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T1, typename T2> ostream &operator<<(ostream &os,const pair<T1,T2> &p) { os<<p.first<<' '<<p.second; return os;}
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ull = unsigned long long;
using ll = long long;
using Pll = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

int main() {
  set<int> hachi;
  range(i,100,1000){
    if(i%8==0){
      hachi.insert(i);
    }
  }


  string s;
  cin>>s;
  if(s.size()<=2){
    if(stoi(s)%8==0){
      cout<<"Yes"<<endl;
      return 0;
    }

    swap(s.front(),s.back());
    if(stoi(s)%8==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
  }

  bool ans=false;
  set<int> nums;
  range(i,0,s.size()){
    int num=s[i]-'0';
    nums.insert(num);
  }
  for(auto v1:nums){
    for(auto v2:nums){
      for(auto v3:nums){
        if(v1==v2||v1==v3||v2==v3) continue;
        int v=v1*100+v2*10+v3;
        if(hachi.find(v)!=hachi.end()){
          ans=true;
        }
      }
    }
  }
  cout<<(ans?"Yes":"No")<<endl;
}