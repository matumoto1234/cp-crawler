// detail: https://atcoder.jp/contests/abc060/submissions/8075916
#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    int flg=0;

    cin>>a>>b>>c;
    for(int i=a;i<a*b;i+=a){
        if(i%b==c){
            flg=1;
            break;
        }
    }
    if(flg==0){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
}

/*
sum=a*n
nは自然数

sum/b=sum%b/b+(sum/b)の整数


*/