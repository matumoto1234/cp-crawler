// detail: https://atcoder.jp/contests/abc080/submissions/20809195
#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;

vector<vector<int>> f(100, vector<int>(10)), p(100, vector<int>(11));

    const ll INF = 1000000000;

int n;

ll search(vector<int> x,ll idx){
    
    if(idx == 11) return -INF;

    ll ans = search(x, idx + 1);
    x[idx] = 1;    
    ans = max(search(x, idx + 1), ans);
    int sum = 0;

    bool flag = false;
    rep(i, 10) if(x[i] == 1) flag = true;
    if(flag == false) return -INF;  

    rep(i, n){
        int num = 0;
     rep(j, 10){
         num += min(x[j], f[i][j]);
     }       
    sum += p[i][num];
    }
    ans = max(ans, (ll)sum);
    return ans;
}


int main() {
    cin >> n;


    rep(i, n) rep(j, 10) cin >> f[i][j];

    rep(i, n) rep(j, 11) cin >> p[i][j];

    vector<int> x(11, 0);




   ll ans = search(x, 0);
    cout << ans << endl;
}