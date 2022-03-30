// detail: https://atcoder.jp/contests/abc116/submissions/30561976
#include<bits/stdc++.h>
#include <atcoder/dsu>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
 
// loop
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>=(b);i--)
 
// Type aliases
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
//vector<vector<int>> A(3, vector<int>(4))
 
// x:コンテナ
#define all(x) x.begin(),x.end() //sort(ALL(x))　昇順ソート
#define rall(x) x.rbegin(),x.rend() //sort(RALL(x)) 降順ソート
#define Size(x) ll(x.size()) // 要素数
 
// const
const int MOD = 1000000007;
 
/* function */
template<class T>
T GCD(T a, T b) {
	if (b != 0) return GCD(b, a % b);
	return a;
}
template<class T>
T LCM(T a, T b) {
	return a / GCD(a, b) * b;
}
 
const int dy[4] = { 0, 1, -1, 0 };
const int dx[4] = { 1, 0, 0, -1 };
 
bool dp[105][10100];

int main(){
    int n,cnt=0;
    cin >> n;
    vector<int> A(n);
    rep(i,0,n){
        cin >> A[i];
    }
  
    A.push_back(0);
  
    for(int j=0;j<=5000;j++){
        int flag=0;
        for(int i=0;i<n;i++){
            if(A[i]==0){
                flag=1;
                continue;
            }
            if(A[i]&&A[i+1]<=0) {
                cnt++;
                A[i]--;
                flag=1;
                continue;
            }
            if(A[i]>0&&A[i+1]>0) {
                A[i]--;
                continue;
            }
            if(i==n-1&&A[i-1]<=0) {
                A[i]--;
                cnt++;
            }
        }
        if(!flag) cnt++;
    }
    cout << cnt << endl;
}