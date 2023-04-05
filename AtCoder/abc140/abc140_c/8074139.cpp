// detail: https://atcoder.jp/contests/abc140/submissions/8074139
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    long long int ans=0;
    vector<int> b(100000);
    vector<int> a(100000);

    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>b[i];
    }
    a[0]=b[0];
    a[n-1]=b[n-2];
    for(int i=1;i<n-1;i++){
        if(b[i]>b[i-1]){
            a[i]=b[i-1];
        }
        else{
            a[i]=b[i];
        }
    }
    for(int i=0;i<n;i++){
        //cout<<a[i]<<endl;
        ans+=a[i];
    }
    cout<<ans<<endl;
}