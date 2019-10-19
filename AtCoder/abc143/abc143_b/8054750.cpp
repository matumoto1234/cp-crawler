// detail: https://atcoder.jp/contests/abc143/submissions/8054750
#include<iostream>
using namespace std;
int main()
{
    int n;
    int d[50];
    int ans=0;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(i==j)continue;
            ans+=d[i]*d[j];
        }
    }
    cout<<ans<<endl;
}