// detail: https://atcoder.jp/contests/abc164/submissions/12348872
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(int argc,char* argv[]){
    int a,b,c,d;
    int flg=0;

    cin>>a>>b>>c>>d;

    while(1){
        c-=a;
        if(c<=0){
            flg=1;
            break;
        }
        a-=d;
        if(a<=0){
            flg=2;
            break;
        }
    }
    if(flg==1){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
    return 0;
}