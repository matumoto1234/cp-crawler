// detail: https://atcoder.jp/contests/arc113/submissions/20392049
#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T1, typename T2> ostream &operator<<(ostream &os,const pair<T1,T2> &p) { os<<p.first<<' '<<p.second<<'\n'; return os;}
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ll = long long;
using PL = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';


void v_reset(vector<int> &v,int c){
  range(i,0,v.size()){
    if(i==c) continue;
    v[i]=0;
  }
}


int main() {
  string s;
  cin>>s;
  ll ans=0;

  //char prev='A';
  vector<int> index(26,s.size());
  vector<int> cnt(26,0);

  rrange(i,1,s.size()){

    int c=s[i]-'a';

    if(s[i-1]==s[i]){

      //int len=index[c]-(i+1);
      int len=s.size()-(i+1);

      int num=len-cnt[c];

      ans+=num;

      //cerr<<"ans:"<<ans<<" i:"<<i<<" len:"<<len<<" num:"<<num<<endl;

      v_reset(cnt,c);
      //v_reset(index,c);
      cnt[c]+=num;
      //index[c]=i-1;
    }

    cnt[c]++;
  }
  cout<<ans<<endl;
}