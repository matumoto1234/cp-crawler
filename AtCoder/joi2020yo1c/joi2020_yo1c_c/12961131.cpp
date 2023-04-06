// detail: https://atcoder.jp/contests/joi2020yo1c/submissions/12961131
#include<bits/stdc++.h>
using namespace std;
int main(int argc,char* argv[]){
    int n;
    cin>>n;
    vector<int> a(n);
    int max,r,l;
    max=r=l=0;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        if(a[i]>=a[i-1]){
            r++;
        }else{
            if(max<r-l+1){
                max=r-l+1;
            }
            r=l=i;
        }
    }
    if(max<r-l+1){
        max=r-l+1;
    }
    cout<<max<<endl;
    return 0;
}