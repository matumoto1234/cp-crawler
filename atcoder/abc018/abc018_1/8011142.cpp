// detail: https://atcoder.jp/contests/abc018/submissions/8011142
#include<iostream>
using namespace std;
int main()
{
    int a[3];
    int b[3]={1,2,3};
    cin>>a[0]>>a[1]>>a[2];
    for(int i=0;i<2;i++){
        for(int j=i+1;j<3;j++){
            if(a[i]<a[j]){
                int tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
                tmp=b[i];
                b[i]=b[j];
                b[j]=tmp;
            }
        }
    }
    cout<<b[0]<<"\n"<<b[1]<<"\n"<<b[2]<<endl;
}