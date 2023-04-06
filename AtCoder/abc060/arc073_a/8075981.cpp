// detail: https://atcoder.jp/contests/abc060/submissions/8075981
#include<iostream>
using namespace std;
int main()
{
    int n,t;
    int l[200000];
    int sum;

    cin>>n>>t;
    for(int i=0;i<n;i++){
        cin>>l[i];
    }
    sum=t;
    for(int i=1;i<n;i++){
        if(l[i]-l[i-1]>t){
            sum+=t;
        }
        else{
            sum+=l[i]-l[i-1];
        }
    }
    cout<<sum<<endl;
}