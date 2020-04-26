// detail: https://atcoder.jp/contests/abc164/submissions/12378661
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int comp_char(const void*a,const void*b){
    char *aa=(char*)a;
    char *bb=(char*)b;
    return strcmp(aa,bb);
}

int main(int argc,char* argv[]){
    int n;
    int ans=1;
    static char s[200000][11];
    //vector<vector<char>> s(200000,vector<char>(11));

    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
    }
    qsort(s,n,sizeof(s[0]),comp_char);
    for(int i=1;i<n;i++){
        //printf("---%s\n",s[i-1]);
        if(!strcmp(s[i],s[i-1])){
            continue;
        }
        else{
            ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}