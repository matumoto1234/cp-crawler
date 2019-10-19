// detail: https://atcoder.jp/contests/abc143/submissions/8054773
#include<iostream>
using namespace std;
int main()
{
    int n;
    int l[2000];
    int ans=0;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>l[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(l[i]<l[j]+l[k]&&l[j]<l[i]+l[k]&&l[k]<l[i]+l[j]){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
}