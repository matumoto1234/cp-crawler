// detail: https://atcoder.jp/contests/abc091/submissions/41655707
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;

  vector<ll> a(n);
  for (auto &v: a) {
    cin >> v;
  }

  vector<ll> b(n);
  for (auto &v: b) {
    cin >> v;
  }

  int ans = 0;

  // k-bit目を見る
  // T = 2^kとしたとき、
  // (ai + bj) % 2T < 4Tが成り立つ
  // (ai + bj) mod 2Tのk-bit目の01は以下のような性質がある
  // [ 0,  T) = 0
  // [ T, 2T) = 1
  // [2T, 3T) = 0
  // [3T, 4T) = 1
  // ※これはk-bit目が偶数回1加算されれば0、k-bit目が奇数回1加算されれば1であるから

  // 各aについてi、ai+bj ∈ [T, 2T) or ai+bj ∈ [3T,4T)なるjの個数をcnt_jとする
  // cnt_jの和をcntとしたとき、
  // cntがk-bit目に1が登場する回数なので、k-bit目の01はcntの偶奇によって決まる
  for (int k = 0; k < 28; k++) {
    int T = 1 << k;

    auto mod_a = a;
    for (auto &v: mod_a) {
      v %= 2 * T;
    }

    auto mod_b = b;
    for (auto &v: mod_b) {
      v %= 2 * T;
    }

    sort(mod_b.begin(), mod_b.end());

    int cnt = 0;

    for (auto ai: mod_a) {
      // T <= ai+bj and ai+bj < 2T
      // T-ai <= bj and bj < 2T-ai
      int l1 = lower_bound(mod_b.begin(), mod_b.end(), T - ai) - mod_b.begin();

      int valid = 0;
      int invalid = mod_b.size();
      while (abs(valid - invalid) > 1) {
        int mid = (valid + invalid) / 2;
        if (mod_b[mid] < 2 * T - ai) {
          valid = mid;
        } else {
          invalid = mid;
        }
      }

      int r1 = valid + 1;

      // 3T <= ai+bj and ai+bj < 4T
      // 3T-ai <= bj and bj < 4T-ai
      int l2 = lower_bound(mod_b.begin(), mod_b.end(), 3 * T - ai) - mod_b.begin();

      valid = 0;
      invalid = mod_b.size();
      while (abs(valid - invalid) > 1) {
        int mid = (valid + invalid) / 2;
        if (mod_b[mid] < 4 * T - ai) {
          valid = mid;
        } else {
          invalid = mid;
        }
      }

      int r2 = valid + 1;

      // [l1, r1), [l2, r2)の区間に適していない場合は0
      int cnt_j = max(0, r1 - l1) + max(0, r2 - l2);

      cnt += cnt_j;
    }

    if (cnt % 2 == 1) {
      ans |= 1 << k;
    }
  }

  cout << ans << endl;
}