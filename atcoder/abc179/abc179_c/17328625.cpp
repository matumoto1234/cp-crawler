// detail: https://atcoder.jp/contests/abc179/submissions/17328625
#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i*j<n){
                //printf("%d %d\n",i,j);
                cnt++;
            }else break;
        }
    }
    
    printf("%d\n",cnt);
    return 0;
}

