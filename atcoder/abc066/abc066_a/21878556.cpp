// detail: https://atcoder.jp/contests/abc066/submissions/21878556
#include <iostream>
using namespace std;

int main(){
    int n;
    long a[1000000001];
    long b[1000000001];

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        for(int j = 0; j <= i; j++){
            b[j] = a[i - j];
        }
         for(int j = 0; j <= i; j++){
            a[j] = b[j];
        }
    }

    for(int i = 0; i < n; i++){
        cout << b[i] << endl;
    }
    return 0;
}