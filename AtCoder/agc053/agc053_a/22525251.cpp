// detail: https://atcoder.jp/contests/agc053/submissions/22525251
#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define range(i, l, r) for ( int i = (int)(l); i < (int)(r); (i) += 1 )
#define rrange(i, l, r) for ( int i = (int)(r)-1; i >= (int)(l); (i) -= 1 )
#define debug(x) cerr << "(" << __LINE__ << ") " << #x << ": " << (x) << endl;
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << p.first << ' ' << p.second; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &v) { for ( pair<T1, T2> x : v ) { os << x << (x.first == v.rbegin()->first && x.second == v.rbegin()->second ? "" : "\n"); } return os; }
template <typename T> ostream &operator<<(ostream &os, queue<T> v) { if(!v.empty()) { os << v.front(); v.pop(); } while (!v.empty()) { os << " " << v.front(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, stack<T> v) { if(!v.empty()) { os << v.top(); v.pop(); } while (!v.empty()) { os << " " << v.top(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { range(i,0,v.size()) { os << (i ? " " : "") << v[i]; } return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &v) { for ( T x : v ) { os << (x == v.front() ? "" : " ") << x; } return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) { for ( T x : v ) { os << (x == *v.begin() ? "" : " ") << x; } return os; }
using ull = unsigned long long;
using ll = long long;
using Pll = pair<ll, ll>;
using P = pair<int, int>;
constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr int dy[] = { 0, -1, 1, 0, -1, 1, -1, 1 };
constexpr int dx[] = { -1, 0, 0, 1, -1, -1, 1, 1 };
constexpr int mod998244353 = 998244353;
constexpr int mod1000000007 = (int)1e9 + 7;
constexpr char newl = '\n';
// clang-format on

vector<pair<char,int>> runlength(string vs){
  vector<pair<char,int>> res;
  for(auto v:vs){
    if(res.empty() || res.back().first!=v) res.emplace_back(v,0);
    res.back().second++;
  }
  return res;
}

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> a(n+1);
  range(i,0,n+1){
    cin>>a[i];
  }

  auto vs = runlength(s);

  if(vs.back().first == '<') vs.emplace_back('>',0);
  else vs.emplace_back('<',0);

  vector<int> minvs;
  range(i,0,vs.size()-1){
    auto [c,cnt]=vs[i];
    auto &[nc,ncnt]=vs[i+1];
    if(c=='<' && nc=='>'){
      if(cnt > ncnt) ncnt--;
      else cnt--;
      range(j,0,cnt+1){
        minvs.emplace_back(j);
      }
    }
    else{
      rrange(j,1,cnt+1){
        minvs.emplace_back(j);
      }
    }
  }


  vector<vector<int>> ans;
  while(1){
    vector<int> cp = a;
    range(i,0,n+1){
      cp[i]-=minvs[i];
      if(cp[i]<0){
        ans.emplace_back(a);
        break;
      }
    }
    bool flg = false;
    range(i,0,n){
      if(s[i]=='<' && cp[i] >= cp[i+1]){
        flg = true;
        break;
      }else if(s[i]=='>' && cp[i] <= cp[i+1]){
        flg = true;
        break;
      }
    }
    if(flg){
      ans.emplace_back(a);
      break;
    }
    ans.emplace_back(minvs);
    range(i,0,n+1) a[i]-=minvs[i];
  }

  cout<<ans.size()<<endl;
  range(i,0,ans.size()){
    cout<<ans[i]<<newl;
  }
}