// detail: https://atcoder.jp/contests/abc079/submissions/8075160
#include<iostream>
using namespace std;
int main()
{
    int n;
    long long int l[86];

    cin>>n;
    l[0]=2;
    l[1]=1;
    for(int i=2;i<=n;i++){
        l[i]=l[i-1]+l[i-2];
    }
    cout<<l[n]<<endl;
}