// detail: https://atcoder.jp/contests/joi2020yo1a/submissions/12960597
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m),c;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    while(1){
        if(a[0]<=b[0]){
            c.emplace_back(a[0]);
            a.erase(a.begin());
        }else{
            c.emplace_back(b[0]);
            b.erase(b.begin());
        }
        if(a.empty()){
            c.insert(c.end(),b.begin(),b.end());
            break;
        }else if(b.empty()){
            c.insert(c.end(),a.begin(),a.end());
            break;
        }
    }
    for(auto x:c)cout<<x<<endl;
    return 0;
}