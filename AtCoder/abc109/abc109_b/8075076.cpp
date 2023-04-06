// detail: https://atcoder.jp/contests/abc109/submissions/8075076
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main()
{
    int n;
    char w[100000][11];
    int flg=0;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int i=1;i<n;i++){
        if(w[i-1][strlen(w[i-1])-1]!=w[i][0]){
            flg=1;
            break;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(strcmp(w[i],w[j])<0){
                char tmp[11];
                strcpy(tmp,w[i]);
                strcpy(w[i],w[j]);
                strcpy(w[j],tmp);
            }
        }
    }
    for(int i=1;i<n;i++){
        if(strcmp(w[i],w[i-1])==0){
            flg=1;
            break;
        }
    }
    //for(int i=0;i<n;i++)cout<<w[i]<<endl;
    if(flg==1){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }
}