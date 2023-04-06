// detail: https://atcoder.jp/contests/abc095/submissions/19542638
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct sushi {
  ll x, v;
};

template <typename T>
struct SparseTable {
  vector<vector<T>> st;
  vector<int> lookup;

  SparseTable(const vector<T> &v) {
    int b = 0;
    while ((1 << b) <= v.size())
      ++b;
    st.assign(b, vector<T>(1 << b));
    for (int i = 0; i < v.size(); i++) {
      st[0][i] = v[i];
    }
    for (int i = 1; i < b; i++) {
      for (int j = 0; j + (1 << i) <= (1 << b); j++) {
        st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
    lookup.resize(v.size() + 1);
    for (int i = 2; i < lookup.size(); i++) {
      lookup[i] = lookup[i >> 1] + 1;
    }
  }

  inline T rmq(int l, int r) {
    int b = lookup[r - l];
    return max(st[b][l], st[b][r - (1 << b)]);
  }
};

template <typename T>
void debug(const vector<T>& v){
  int n=v.size();
  for(int i=0;i<n;i++){
    if(i) cerr<<' ';
    cerr<<v[i];
  }
  cerr<<"\n";
}

ll n, c;

ll solve(vector<sushi> a) {
  // r[i]:=右回りでi番目に到達し、0番目に戻ったときの値
  // (最後だけは0に戻らなくてよい)
  vector<ll> r(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i].v;
    r[i] = sum - a[i].x;
    if(i<=n-2) r[i]-=a[i].x;
  }

  // l[i]:=左回りでi番目に到達したときの値
  vector<ll> l(n);
  sum = 0;
  for (int i = n-1; i >= 0; i--) {
    sum += a[i].v;
    l[i] = sum - (c - a[i].x);
  }

//  cerr<<"---left---"<<endl;
//  debug(l);
//
//  cerr<<"---right---"<<endl;
//  debug(r);

  SparseTable<ll> r_table(r);
  SparseTable<ll> l_table(l);

  ll res=0;
  for(int i=0;i<n-1;i++){
    ll vr=r_table.rmq(0,i+1);
    ll vl=l_table.rmq(i+1,n);

    //cerr<<"vr:"<<vr<<" vl:"<<vl<<endl;
    res=max({vr+vl, vr, res});
  }
  //cerr<<res<<endl;
  return res;
}

int main() {
  cin >> n >> c;
  vector<sushi> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].v;
  }

  ll v1 = solve(a);
  for (int i = 0; i < n; i++)
    a[i].x = c - a[i].x;
  reverse(a.begin(), a.end());
  ll v2 = solve(a);
  cout << max(v1, v2) << endl;
}