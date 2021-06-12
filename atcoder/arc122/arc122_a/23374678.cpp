// detail: https://atcoder.jp/contests/arc122/submissions/23374678
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/modint.hpp>
using mint=atcoder::modint1000000007;

// {{{

// clang-format off
#define rep(i, n) for (int i = 0; i < (int)(n); i += 1)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; i -= 1)
#define range(i, l, r) for ( int i = (int)(l); i < (int)(r); (i) += 1 )
#define rrange(i, l, r) for ( int i = (int)(r)-1; i >= (int)(l); (i) -= 1 )
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
template <typename T> void operator+=(vector<T> &vs, T x) { for ( T &v : vs ) v += x; }
template <typename T> void operator-=(vector<T> &vs, T x) { for ( T &v : vs ) v -= x; }
template <typename T> void operator*=(vector<T> &vs, T x) { for ( T &v : vs ) v *= x; }
template <typename T> void operator/=(vector<T> &vs, T x) { for ( T &v : vs ) v /= x; }
template <typename T> void operator%=(vector<T> &vs, T x) { for ( T &v : vs ) v %= x; }
template <typename T> vector<T> operator+(const vector<T> &vs, T x) { vector<T> res = vs; for ( T &v : res ) v += x; return res; }
template <typename T> vector<T> operator-(const vector<T> &vs, T x) { vector<T> res = vs; for ( T &v : res ) v -= x; return res; }
template <typename T> vector<T> operator*(const vector<T> &vs, T x) { vector<T> res = vs; for ( T &v : res ) v *= x; return res; }
template <typename T> vector<T> operator/(const vector<T> &vs, T x) { vector<T> res = vs; for ( T &v : res ) v /= x; return res; }
template <typename T> vector<T> operator%(const vector<T> &vs, T x) { vector<T> res = vs; for ( T &v : res ) v %= x; return res; }
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


void naive(int n){
	int ans=0;
	vector<int> sum(n-1,0);
	rep(i,1<<(n-1)){
		vector<bool> minus(n-1,false);
		rep(j,n-1){
			if(i>>j&1){
				minus[j]=true;
			}
		}

		bool valid=true;
		range(j,1,n-1){
			if(minus[j-1] && minus[j]){
				valid=false;
				break;
			}
		}
		if(valid){
			cerr<<minus<<endl;
			rep(j,n-1){
				sum[j]+=minus[j];
			}
			ans++;
		}
	}
	cout<<"n:"<<n<<" ans:"<<ans<<endl;
	cout<<sum<<endl;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin>>n;

	vector<int> a(n);
	for(auto &A:a)cin>>A;

	vector<mint> fib(n+1,0);
	fib[0]=fib[1]=1;
	for(int i=2;i<=n;i++){
		fib[i]=fib[i-1]+fib[i-2];
	}

	mint all=0;
	for(int i=0;i<n;i++){
		all+=fib[n]*a[i];
	}

	vector<vector<mint>> dp(n+1);
	dp[0].emplace_back(0);
	dp[1].emplace_back(1);
	dp[2].emplace_back(1);
	dp[2].emplace_back(1);
	dp[3].emplace_back(2);
	dp[3].emplace_back(1);
	dp[3].emplace_back(2);
	for(int i=4;i<=n;i++){
		dp[i].reserve(i/2+1);
		for(int j=0;j<=(i+1)/2;j++){
			mint v1=0,v2=0;
			if(j>(i-1+1)/2){
				v1=dp[i-1][i-1-1-j];
			} else{
				v1=dp[i-1][j];
			}

			if(j>(i-2+1)/2){
				v2=dp[i-2][i-2-1-j];
			} else{
				v2=dp[i-2][j];
			}
			dp[i].emplace_back(v1+v2);
		}
	}

	// for(int i=0;i<=n;i++){
	// 	for(int j=0;j<(int)dp[i].size();j++){
	// 		if(j) cerr<<" ";
	// 		cerr<<dp[i][j].val();
	// 	}
	// 	cerr<<newl;
	// }

	vector<mint> nums;
	rep(i,(n-1+1)/2){
		nums.emplace_back(dp[n-1][i]);
	}
	rrep(i,(n-1)/2){
		nums.emplace_back(dp[n-1][i]);
	}

	range(i,1,n){
		all-=nums[i-1]*a[i]*2;
	}

	cout<<all.val()<<endl;

	// rep(i,nums.size()){
	// 	if(i) cerr<<" ";
	// 	cerr<<nums[i].val();
	// }
	// cerr<<endl;
}