// detail: https://atcoder.jp/contests/abc194/submissions/29920125
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<ll> A(n),cnt(405);//Aiが何回出るかカウント
    rep(i,0,n) {
        cin >> A[i];
        cnt[A[i]+200]++;
    }
    ll ans=0;
    for(ll i=0;i<=400;i++){
        for(ll j=i;j<=400;j++){
            ans+=cnt[i]*cnt[j]*(j-i)*(j-i);
        }
    }
    cout << ans ;
}