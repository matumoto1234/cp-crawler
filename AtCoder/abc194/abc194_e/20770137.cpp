// detail: https://atcoder.jp/contests/abc194/submissions/20770137
#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using Pii = pair<int, int>;



int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> cnt(n + 1, 0);

    rep(i, m) {
        cnt[a[i]]++;
    }

    ll ans;

    rep(i, n+1) {
        if(cnt[i] == 0) {
            ans = i;
            break;
        }
    }

    for(int i = m;i < n;i++) {
        cnt[a[i]]++;
        cnt[a[i-m]]--;

        if(!cnt[a[i-m]]) {
            ans = min(cnt[a[i-m]], ans);
        }

    }

    cout << ans << endl;

}

