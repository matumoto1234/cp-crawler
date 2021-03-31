// detail: https://atcoder.jp/contests/abc071/submissions/21420832
#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {

    int n;
    cin >> n;

    string s[2];

    cin >> s[0] >> s[1];

    vector<ll> dp(n + 1, 0);

    if(n == 1) {
        
        set<char> c;
        c.insert(s[0][0]);
        c.insert(s[1][0]);
        if(c.size() == 2) {
            cout << 6 << endl;
        }
        else cout << 3 << endl;
        return 0;
    }


    rep(i, n) {
        // if(i == 0) continue;
        // cout << i + 1 << endl;

        if(i == 0) {
            if(s[0][0] == s[1][0]) { //縦
                
                dp[i] = 3;
            }
            else {
                dp[i] = 6;  
                i++;
            }
        // cout << dp[i] << endl;
            continue;
        }
        if(s[0][i - 1] != s[1][i - 1]) { // 横
            
            if(s[0][i] == s[1][i]) { //たて
                dp[i] = dp[i - 1];
                dp[i] %= MOD;
            }

            else { //横
                dp[i] = dp[i - 1] * 3;
                dp[i] %= MOD;
                dp[i + 1] = dp[i];
                i++;
            }

        } 
        else  { // iがたて 
            if(s[0][i] == s[1][i]) {
            dp[i] = dp[i - 1] * 2;
            dp[i] %= MOD;
            }
        
            else {//　横
            dp[i] = dp[i - 1]*2;
            dp[i] %= MOD;
            dp[i + 1] = dp[i];
            i++;
            }
        }
        
    }
    // int cnt = n;
    // while(dp[cnt] == 0) cnt--;

    cout << dp[n - 1] << endl;

    // cout << s[0][3] << " " << s[1][3] << endl;

    return 0;
}