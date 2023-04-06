// detail: https://atcoder.jp/contests/abc167/submissions/13055748
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    t.erase(t.size()-1);
    if(s==t){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}