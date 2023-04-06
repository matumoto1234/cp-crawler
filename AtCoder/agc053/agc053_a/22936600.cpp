// detail: https://atcoder.jp/contests/agc053/submissions/22936600
#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define range(i, l, r) for ( int i = (int)(l); i < (int)(r); (i) += 1 )
#define rrange(i, l, r) for ( int i = (int)(r)-1; i >= (int)(l); (i) -= 1 )
#define debug(x) cerr << #x << ": " << (x) << endl;
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << p.first << ' ' << p.second; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &v) { for ( pair<T1, T2> x : v ) { os << x << "\n"; } return os; }
template <typename T> ostream &operator<<(ostream &os, queue<T> v) { if(!v.empty()) { os << v.front(); v.pop(); } while (!v.empty()) { os << " " << v.front(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, stack<T> v) { if(!v.empty()) { os << v.top(); v.pop(); } while (!v.empty()) { os << " " << v.top(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
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

vector<pair<char,int>> Runlength(string s){
  vector<pair<char,int>> res;
  for(auto v:s){
    if(res.empty() || res.back().first!=v) res.emplace_back(v,0);
    res.back().second++;
  }
  return res;
}

bool is_valid(const string &s,const vector<int> &vs){
  range(i,0,s.size()){
    if(s[i]=='>' && vs[i] <= vs[i+1]){
      return false;
    }
    if(s[i]=='<' && vs[i] >= vs[i+1]){
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  string s;
  cin>>s;
  vector<int> a(n+1);
  for(auto &A:a) cin>>A;
  auto vs = Runlength(s);

  if(vs.back().first=='<') vs.emplace_back('>',INF32);
  else vs.emplace_back('<',INF32);

  vector<int> minvs;
  range(i,0,vs.size()-1){
    auto [c,cnt]=vs[i];
    auto &[nc,ncnt]=vs[i+1];
    if(c=='>' && nc=='<'){
      for(int j=cnt;j>=0;j--){
        minvs.emplace_back(j);
      }
    }else{
      if(cnt>ncnt){
        // <<<>>
        // 0123 210
        int start=1;
        if(i==0) start=0;
        for(int j=start;j<cnt;j++){
          minvs.emplace_back(j);
        }
        minvs.emplace_back(ncnt);
      }else{
        // <<>>>
        // 012 3210
        int start=1;
        if(i==0) start=0;
        for(int j=start;j<=cnt;j++){
          minvs.emplace_back(j);
        }
        ncnt--;
      }
    }
  }

  // debug(minvs);
  int k=0;
  vector<vector<int>> ans;
  while(1){
    k++;
    range(i,0,a.size()) a[i]-=minvs[i];
    if(is_valid(s,a)){
      ans.push_back(minvs);
      continue;
    }
    // debug(a);
    range(i,0,a.size()) a[i]+=minvs[i];
    ans.push_back(a);
    break;
  }
  cout<<k<<endl;
  for(vector<int> v:ans){
    cout<<v<<newl;
  }
}