// detail: https://atcoder.jp/contests/typical90/submissions/42995013
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int n, l;
  cin >> n >> l;

  int k;
  cin >> k;

  vector<int> a(n);
  for (auto &v: a) {
    cin >> v;
  }

  a.insert(a.begin(), 0);
  a.push_back(l);
  n += 2;

  ll valid = 0;
  ll invalid = (1LL << 60);

  auto is_valid = [&](ll x) -> bool {
    ll sum = 0;
    int cut_count = 0;
    for (int i = 0; i < n - 1; i++) {
      ll diff = a[i + 1] - a[i];
      sum += diff;
      if (sum >= x) {
        sum = 0;
        cut_count++;
      }
    }

    if (sum < x) {
      cut_count--;
    }

    return cut_count >= k;
  };

  while (abs(valid - invalid) > 1) {
    ll mid = (valid + invalid) / 2;
    if (is_valid(mid)) {
      valid = mid;
    } else {
      invalid = mid;
    }
  }

  cout << valid << endl;
}