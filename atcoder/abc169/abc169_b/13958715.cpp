// detail: https://atcoder.jp/contests/abc169/submissions/13958715
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long int> a(n-1);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0){
            cout<<0<<endl;
            return 0;
        }
    }
    for(int j=1;j<n;j++){
        if(a[j]>1000000000&&a[j-1]>=1000000000){
            cout<<-1<<endl;
            return 0;
        }
        else if(a[j]>=1000000000&&a[j-1]>1000000000){
            cout<<-1<<endl;
            return 0;
        }
        if(a[j]*a[j-1]>1000000000000000000){
            cout<<-1<<endl;
            return 0;
        }
        a[j]*=a[j-1];
    }
    cout<<a[n-1]<<endl;
}
