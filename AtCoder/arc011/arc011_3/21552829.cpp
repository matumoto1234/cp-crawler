// detail: https://atcoder.jp/contests/arc011/submissions/21552829
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

string first,last;
int n;
set<string> words;
vector<string> st;
bool dfs(string &s,int prev){
  // cerr<<s<<' '<<prev<<endl;

  bool res=false;
  range(idx,0,s.size()){
    if(prev==idx) continue;
    range(i,0,26){
      char c='a'+i;
      if(s[idx]==c) continue;
      swap(s[idx],c);
      if(s==last){
        st.emplace_back(s);
        swap(s[idx],c);
        return true;
      }
      if(words.find(s)!=words.end()){
        res|=dfs(s,idx);
      }
      swap(s[idx],c);
      if(res){
        st.emplace_back(s);
        break;
      }
    }
  }
  return res;
}

int main() {
  cin>>first>>last;
  cin>>n;
  range(i,0,n){
    string s;
    cin>>s;
    words.insert(s);
  }

  if(first==last){
    cout<<0<<endl;
    cout<<first<<endl;
    cout<<last<<endl;
    return 0;
  }

  if(dfs(first,-1)){
    st.erase(unique(st.begin(),st.end()),st.end());
    cout<<st.size()-2<<endl;
    rrange(i,0,st.size()){
      cout<<st[i]<<'\n';
    }
  }else{
    cout<<-1<<endl;
  }
}