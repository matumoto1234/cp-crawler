// detail: https://atcoder.jp/contests/abc138/submissions/12240177
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

typedef struct{
    int a,b;
}strKi;

typedef struct node{
    int num;
    node* oya;
    node* ko;
}strKi2;

bool asc(const strKi& left,const strKi& right){
    return left.a==right.a?left.b<right.b:left.a<right.a;
}

int main(void){
    int n,q;

    cin>>n>>q;
    vector<strKi> hen(n-1);
    vector<int> p(q-1),x(q);
    vector<strKi2> ki(n);

    for(int i=0;i<n;i++) ki[i].num=0;
    for(int i=0;i<n-1;i++) {
        cin>>hen[i].a>>hen[i].b;

        ki[hen[i].a-1].ko=&ki[hen[i].b-1];
        ki[hen[i].b-1].oya=&ki[hen[i].a-1];

    }
    for(int i=0;i<q;i++) {
        cin>>p[i]>>x[i];
        ki[p[i]-1].num+=x[i];
    }
    //sort(hen.begin(),hen.end(),asc);

    for(int i=1;i<n;i++){
        ki[i].num+=ki[i].oya->num;
    }
    for(int i=0;i<n;i++){
        cout<<ki[i].num<<endl;
    }

    return 0;
}