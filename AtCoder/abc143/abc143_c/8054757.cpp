// detail: https://atcoder.jp/contests/abc143/submissions/8054757
#include<iostream>
using namespace std;
int main()
{
    int n;
    char s[100001];
    int ans=1;

    cin>>n>>s;
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[i+1]){
            ans++;
        }
    }
    cout<<ans<<endl;
}