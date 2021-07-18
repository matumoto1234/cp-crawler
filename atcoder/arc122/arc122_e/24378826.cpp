// detail: https://atcoder.jp/contests/arc122/submissions/24378826
#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>

namespace inner {
using u32 = uint32_t;
using u64 = uint64_t;
using i64 = int64_t;
using u128 = __uint128_t;

u64 gcd_impl(u64 n, u64 m) {
	constexpr u64 K = 5;
	for(int i = 0; i < 80; ++i) {
		u64 t = n - m;
		u64 s = n - m * K;
		bool q = t < m;
		bool p = t < m * K;
		n = q ? m : t;
		m = q ? t : m;
		if(m == 0) return n;
		n = p ? n : s;
	}
	return gcd_impl(m, n % m);
}

u64 gcd_pre(u64 n, u64 m) {
	for(int i = 0; i < 4; ++i) {
		u64 t = n - m;
		bool q = t < m;
		n = q ? m : t;
		m = q ? t : m;
		if(m == 0) return n;
	}
	return gcd_impl(n, m);
}

u64 gcd_fast(u64 n, u64 m) {
	return n > m ? gcd_pre(n, m) : gcd_pre(m, n);
}

struct modint64 {
	using u64 = uint64_t;

public:
	static u64 mod;
	static u64 r, n2;
	static void set_mod(u64 m) {
		mod = m;
		n2 = -u128(m) % m;
		r = get_r();
		assert(r * mod == 1);
	}
	modint64() : a(0) {}
	modint64(const i64 &b) : a(reduce((u128(b) + mod) * n2)) {}

	modint64 &operator+=(const modint64 &b) {
		if(i64(a += b.a - 2 * mod) < 0) a += 2 * mod;
		return *this;
	}

	modint64 &operator-=(const modint64 &b) {
		if(i64(a -= b.a) < 0) a += 2 * mod;
		return *this;
	}

	modint64 &operator*=(const modint64 &b) {
		a = reduce(u128(a) * b.a);
		return *this;
	}

	modint64 &operator/=(const modint64 &b) {
		*this *= b.inverse();
		return *this;
	}

	modint64 operator+(const modint64 &b) const { return modint64(*this) += b; }
	modint64 operator-(const modint64 &b) const { return modint64(*this) -= b; }
	modint64 operator*(const modint64 &b) const { return modint64(*this) *= b; }
	modint64 operator/(const modint64 &b) const { return modint64(*this) /= b; }

	modint64 pow(u128 n) const {
		modint64 ret(1), mul(*this);
		while(n > 0) {
			if(n & 1) ret *= mul;
			mul *= mul;
			n >>= 1;
		}
		return ret;
	}

	modint64 inverse() const { return pow(mod - 2); }

	u64 val() const {
		u64 ret = reduce(a);
		return ret >= mod ? ret - mod : ret;
	}

	static u64 get_mod() { return mod; }

private:
	u64 a;

	static u64 get_r() {
		u64 ret = mod;
		for(int i = 0; i < 5; i++) ret *= 2 - mod * ret;
		return ret;
	}

	static u64 reduce(const u128 &b) {
		return (b + u128(u64(b) * u64(-r)) * mod) >> 64;
	}
};
typename modint64::u64 modint64::mod, modint64::r, modint64::n2;

u64 rnd() {
	static u64 x = 10150724397891781847ull;
	x ^= x << 7;
	return x ^= x >> 9;
}

bool is_prime(const u64 n) {
	if(~n & 1) return n == 2;
	if(n < (1ll << 30)) return atcoder::internal::is_prime_constexpr(n);
	u64 d = n - 1;
	while(~d & 1) d >>= 1;
	if(modint64::get_mod() != n) modint64::set_mod(n);
	for(const u64 a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
		if(n <= a) break;
		modint64 t = d, y = modint64(a).pow(d);
		while(t.val() != n - 1 and y.val() != 1 and y.val() != n - 1) {
			y *= y;
			t *= 2;
		}
		if(y.val() != n - 1 and ~t.val() & 1) return false;
	}
	return true;
}

u64 pollard_rho(const u64 n) {
	if(~n & 1) return 2;
	if(is_prime(n)) return n;
	if(modint64::get_mod() != n) modint64::set_mod(n);
	modint64 R, one = 1;
	auto f = [&](modint64 x) { return x * x + R; };
	auto rng = [&]() { return rnd() % (n - 2) + 2; };
	for(;;) {
		modint64 x, y(rng()), ys, q = one;
		R = rng();
		u64 g = 1;
		constexpr int m = 128;
		for(int r = 1; g == 1; r <<= 1) {
			x = y;
			for(int i = 0; i < r; i++) y = f(y);
			for(int k = 0; g == 1 and k < r; k += m) {
				ys = y;
				for(int i = 0; i < m and i < r - k; i++) q *= x - (y = f(y));
				g = gcd_fast(q.val(), n);
			}
		}
		if(g == n) do
				g = gcd_fast((x - (ys = f(ys))).val(), n);
			while(g == 1);
		if(g != n) return g;
	}
	exit(1);
}

std::vector<u64> factorize(const u64 n) {
	if(n == 1) return {};
	if(is_prime(n)) return {n};
	auto d = pollard_rho(n);
	auto res = factorize(d);
	auto sub = factorize(n / d);
	std::copy(sub.begin(), sub.end(), std::back_inserter(res));
	return res;
}

};  // namespace inner
using inner::is_prime;

template <typename T>
std::vector<T> factorize(const T n) {
	auto tmp = inner::factorize(n);
	std::vector<T> res{tmp.begin(), tmp.end()};
	std::sort(res.begin(), res.end());
	return res;
}

// {{{

// clang-format off
#define _over_load(_1,_2,_3,_4,NAME,...) NAME
#define range(...) _over_load(__VA_ARGS__, range4, range3, range2)(__VA_ARGS__)
#define range2(i, r) for ( int i = 0; i < (int)(r); (i) += 1)
#define range3(i, l, r) for ( int i = (int)(l); i < (int)(r); (i) += 1)
#define range4(i, l, r, inc) for ( int i = (int)(l); i < (int)(r); (i) += (inc))
#define rrange(...) _over_load(__VA_ARGS__, rrange4, rrange3, rrange2)(__VA_ARGS__)
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
template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }
template <typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &in : v) is >> in; return is; }
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

using mint = atcoder::modint1000000007;

template <typename T>
map<T, T> counter(const vector<T> &vs) {
  map<T, T> res;
  for ( T v : vs ) res[v]++;
  return res;
}

vector<bool> used;
int min_ps_cnt(vector<ll> as){
  vector<Pll> cnts(as.size());
  range(i,as.size()){
    auto &[v,idx]=cnts[i];
    v=factorize(as[i]).size();
    idx=i;
  }

  // debug(as);
  // debug(used);

  int res=0,mi=INF32;
  range(i,cnts.size()){
    if(used[i]) continue;
    if(mi>cnts[i].first){
      mi=cnts[i].first;
      res=cnts[i].second;
    }
  }
  // debug(res,mi);
  return res;
}

// n and MOD are coprime
template <typename T1,typename T2>
T1 modinv(T1 n,T2 MOD){
  using ll = long long;
  function<T1(ll,ll,ll&,ll&)> extgcd = [&](ll a,ll b,ll &x,ll &y){
    if(b==0){
      x=1;
      y=0;
      return a;
    }
    ll d=extgcd(b,a%b,y,x);
    y=y-(a/b)*x;
    return d;
  };

  ll X,Y;
  extgcd(n,MOD,X,Y);
  return (X%MOD+MOD)%MOD;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin>>n;
  vector<ll> as(n);
  cin>>as;

  used.assign(n,false);

  vector<ll> idxs;
  vector<ll> nas=as;
  range(i,n){
    int idx=min_ps_cnt(nas);
    idxs.emplace_back(idx);
    used[idx]=true;
    vector<ll> nnas;
    range(j,n){
      nnas.emplace_back(nas[j]/gcd(nas[idx],nas[j]));
    }
    nas=nnas;
  }

  vector<ll> ans(n);
  ll mod=mod1000000007;
  range(i,n){
    ll a=as[idxs[i]];
    ans[i]=a%mod;
  }

  ll x=1;
  ll pre=1;
  // debug(ans);
  bool valid=true;
  range(i,n){
    ll d=gcd(x,ans[i]);
    x*=ans[i];
    x%=mod;
    x*=modinv(d,mod);
    x%=mod;
    // debug(pre,x);
    if(x==pre) valid=false;
    pre=x;
  }
  if(valid){
    cout<<"Yes"<<endl;
    cout<<ans<<endl;
  }else{
    cout<<"No"<<endl;
  }
}