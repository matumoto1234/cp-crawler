// detail: https://atcoder.jp/contests/abc183/submissions/18162414
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iomanip>
#include <limits>
using namespace std;
#define rep(i, x) for (int i = 0; i < x; i++)

#define ll long long
#define M 1000000

int main(){
    ll n, w;
    ll s, t;
    ll p;
    cin >> n >> w;
    ll pot[M] = {};
    rep(i,n){
        cin >> s >> t >> p;
        pot[s] += p;
        pot[t] -= p;
    }

    for(int i=1; i<M-1; i++){
        pot[i] += pot[i-1];
    }

    long long max = -1000000;
    rep(i,M){
        if(max < pot[i])max = pot[i];
    }
    //cout << max << endl;
    if(max > w){
        cout << "No";
    }else cout << "Yes";
    
}
