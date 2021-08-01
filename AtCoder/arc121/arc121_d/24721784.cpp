// detail: https://atcoder.jp/contests/arc121/submissions/24721784
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define debug(...) debug_func(#__VA_ARGS__, __VA_ARGS__)
template <typename T, typename... T2> void debug_func(string_view name, const T &a, T2 &&...rest) { stack<char> bs; string_view lbs = "({[<"; string_view rbs = ")}]>"; int end = name.size(); for ( int i = 0; i < (int)name.size(); i++ ) { if ( lbs.find(name[i]) != string::npos ) { bs.push(name[i]); } if ( rbs.find(name[i]) != string::npos ) { if ( !bs.empty() ) { bs.pop(); } } if ( name[i] == ',' && bs.empty() ) { end = i; break; } } cerr << name.substr(0, end) << ":" << a; if constexpr ( sizeof...(rest) == 0 ) { cerr << endl; } else { cerr << ' '; debug_func(name.substr(name.find_first_not_of(' ', end + 1)), forward<T2>(rest)...); } }

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }



int main(){
  int n;
  cin>>n;
  vector<ll> as(n);
  for(auto &a:as) cin>>a;
  
  if(n%2){
    as.emplace_back(0);
    n++;
  }
  sort(as.begin(),as.end());
  
  constexpr ll INF = INT64_MAX/2;
  ll ans = INF;
  
  for(int i=0;i<n;i++){
    if(as.size()%2){
      as.emplace_back(0);
      sort(as.begin(),as.end());
      continue;
    }
    ll ma=-INF;
  	ll mi=INF;
    for(int j=0;j<(int)as.size()/2;j++){
      ll v=as[j]+as[n-1-j];
      ma=max(ma,v);
      mi=min(mi,v);
    }
    ans=min(ans,ma-mi);
    as.emplace_back(0);
    sort(as.begin(),as.end());
  }
  cout<<ans<<endl;
}