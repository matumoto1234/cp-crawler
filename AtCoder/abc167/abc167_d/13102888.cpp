// detail: https://atcoder.jp/contests/abc167/submissions/13102888
#include <bits/stdc++.h>
#define loop(i,n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(void){
    ll n, k;
    cin >> n >> k;
    vector<int> a(n), s, done(n+1, -1);
    int c = 1, l = 0;

    loop(i,n){
        cin>>a[i];
    }

    int v = 1;
    while (done[v] == -1){
        done[v] = s.size();
        s.emplace_back(v);
        v = a[v-1];
    }
    c = s.size() - done[v];
    l = done[v];

    if (k < l) cout << s[k] << endl;
    else{
        k -= l;
        k %= c;
        cout << s[l+k] << endl;
    }
    return 0;
}