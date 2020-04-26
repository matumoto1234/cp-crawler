// detail: https://atcoder.jp/contests/abc164/submissions/12397109
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;





int main(int argc,char* argv[]){
    lli n=1817;
    int kan=10;
    lli ans=0;
    lli tmp,iti;

    char s[200001];

    scanf("%s",s);
    for(int i=strlen(s)-1;i>=0;i--){
        if(i-kan>=0){
            tmp=atoll(&s[i-kan]);
            s[i]='\0';
        }
        else{
            tmp=atoll(&s[i]);
        }
        iti=s[i]-'0';
        tmp-=iti*(lli)2;
        if(tmp%2019==0){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}