// detail: https://atcoder.jp/contests/joi2020yo1b/submissions/12960790
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m,0);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[a[i]-1]++;
    }
    sort(b.begin(),b.end());
    cout<<b[b.size()-1]<<endl;
    return 0;
}