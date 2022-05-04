// detail: https://atcoder.jp/contests/abc209/submissions/24143331
#include <bits/stdc++.h>
using namespace std;

// {{{

// clang-format off
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define range(...) GET_MACRO(__VA_ARGS__, range4, range3, range2)(__VA_ARGS__)
#define range2(i, r) for ( int i = 0; i < (int)(r); (i) += 1)
#define range3(i, l, r) for ( int i = (int)(l); i < (int)(r); (i) += 1)
#define range4(i, l, r, inc) for ( int i = (int)(l); i < (int)(r); (i) += (inc))
#define rrange(...) GET_MACRO(__VA_ARGS__, rrange4, rrange3, rrange2)(__VA_ARGS__)
#define rrange2(i, r) for ( int i = (int)(r) - 1; i >= 0; (i) -= 1)
#define rrange3(i, l, r) for ( int i = (int)(r) - 1; i >= (int)(l); (i) -= 1)
#define rrange4(i, l, r, inc) for ( int i = (int)(r) - 1; i >= (int)(l); (i) -= inc)
#define debug(...) debug_func(#__VA_ARGS__, __VA_ARGS__)
template <typename T, typename... T2> void debug_func(string_view name, const T &a, T2 &&...rest) { stack<char> bs; string_view lbs = "({[<"; string_view rbs = ")}]>"; int end = name.size(); for ( int i = 0; i < (int)name.size(); i++ ) { if ( lbs.find(name[i]) != string::npos ) { bs.push(name[i]); } if ( rbs.find(name[i]) != string::npos ) { if ( !bs.empty() ) { bs.pop(); } } if ( name[i] == ',' && bs.empty() ) { end = i; break; } } cerr << name.substr(0, end) << ":" << a; if constexpr ( sizeof...(rest) == 0 ) { cerr << endl; } else { cerr << ' '; debug_func(name.substr(name.find_first_not_of(' ', end + 1)), forward<T2>(rest)...); } }
template <typename T> vector<T> make_vector(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_vector(size_t a, Ts... ts) { return vector<decltype(make_vector(ts...))>(a, make_vector(ts...)); }
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

// }}}


string substr(string &s,int l,int r,bool rflg=false){
  string res="";
  if(rflg) for(int i=r-1;i>=l;i--) res+=s[i];
  else for(int i=l;i<r;i++) res+=s[i];
  return res;
}


vector<string> words;
vector<int> ans;
vector<vector<int>> dp;
set<string> used;
map<string,vector<int>> front_idxs;
map<string,vector<int>> back_idxs;
int dfs(int idx,int depth){
  string word=words[idx];
  // 無限ループに入るとき
  if(used.find(word)!=used.end()){
    // return depth-1;
    return -2;
  }
  used.insert(word);

  // string front=substr(word,0,3);
  string back=substr(word,word.size()-3,word.size());



  // メモ化
  int &res = dp[idx][depth%2];
  if(res!=-1) return res;


  bool won=false,draw=false;
  auto tos=front_idxs[back];
  for(int to:tos){
    // Takahashiのターン
    if(depth%2==0){
      int tmp=dfs(to,depth+1)-depth;
      // draw
      if(tmp<=-2){
        if(!won) res=tmp;
        draw=true;
      // win
      }else if(tmp%2==0){
        res=tmp;
        won=true;
      // lose
      }else{
        if(!won && !draw) res=tmp;
      }
      continue;
    }

    // Aokiのターン
    int tmp=dfs(to,depth+1)-depth;

    if(tmp<=-2){
      if(!won) res=tmp;
      draw=true;
    // win
    } else if(tmp%2){
      res=tmp;
      won=true;
    // lose
    }else{
      if(!won && !draw) res=tmp;
    }
  }
  return res;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin>>n;
  words.resize(n);
  for(auto &word:words){
    cin>>word;
  }

  range(i,n){
    string word=words[i];
    front_idxs[substr(word,0,3)].emplace_back(i);
    back_idxs[substr(word,word.size()-3,word.size())].emplace_back(i);
  }

  dp.assign(n,vector<int>(2,-1));
  range(i,n){
    if(dp[i][0]==-1){
      dfs(i,0);
    }
  }

  range(i,n){
    int ans=dp[i][0];
    if(ans==-2){
      cout<<"Draw"<<newl;
    }else if(ans%2==0){
      cout<<"Takahashi"<<newl;
    }else{
      cout<<"Aoki"<<newl;
    }
  }
}