// detail: https://atcoder.jp/contests/abc015/submissions/8011035
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char a[51],b[51];

    cin>>a>>b;
    if(strlen(a)>strlen(b)){
        cout<<a<<endl;
    }
    else{
        cout<<b<<endl;
    }
}