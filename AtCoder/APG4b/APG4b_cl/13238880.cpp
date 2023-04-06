// detail: https://atcoder.jp/contests/APG4b/submissions/13238880
#include <bits/stdc++.h>
#define loop(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(void){
    int n,a;
    cin >> n >> a;

    vector<char> op(n);
    vector<int> b(n);

    loop(i, n){
        cin >> op[i] >> b[i];
        switch(op[i]){
            case '+':
                cout << a + b[i] << endl;
                break;
            case '-':
                cout << a - b[i] << endl;
                break;
            case '*':
                cout << a * b[i] << endl;
                break;
            case '/':
                if(b[i] == 0){
                    cout << "error" << endl;
                }else{
                    cout << a / b[i] << endl;
                }
                break;
        }
    }
    return 0;
}