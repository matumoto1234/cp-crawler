// detail: https://atcoder.jp/contests/abc143/submissions/8057260
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
int int_comp(const void*a,const void*b){return *(int*)a-*(int*)b;}
using namespace std;
int main()
{
    int n;
    int l[2000];
    int ans=0,flg=0;
    int j,k;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>l[i];
    }
    qsort(l,n,sizeof(int),int_comp);
    for(int i=0;i<n;i++){
        flg=0;
        for(j=i+1;j<n;j++){
            flg=0;
            for(k=j+1;k<n;k++){
                if(l[i]<l[j]+l[k]&&l[j]<l[i]+l[k]&&l[k]<l[i]+l[j]){
                    ans++;
                }
                else{
                    flg=1;
                }
                if(flg==1)break;
            }
            //if(flg==1)break;
        }
    }
    cout<<ans<<endl;
}