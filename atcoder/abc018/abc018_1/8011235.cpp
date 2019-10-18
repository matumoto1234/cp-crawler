// detail: https://atcoder.jp/contests/abc018/submissions/8011235
#include<iostream>
using namespace std;
int main()
{
    int a[3];
    int b[3]={1,2,3};
    int rank[101]={0};
    cin>>a[0]>>a[1]>>a[2];
    for(int i=0;i<3;i++){
        rank[a[i]-1]++;
    }
    rank[100]=1;
    for(int i=99;i>=0;i--){
        rank[i]=rank[i+1]+rank[i];
    }
    for(int i=0;i<3;i++){
        cout<<rank[a[i]]<<endl;
    }
}