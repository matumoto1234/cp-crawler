// detail: https://atcoder.jp/contests/abc150/submissions/9401592
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
typedef long long int lli;

int num[110];
int frag[110];
int q[8], p[8];
lli pp, qq, cnt=0;
void fx(int n, int k)
{
    int i, f, j;
    for (i = 0; i < n; ++i)
    {
        f = frag[i];
        if (f == 0)
        {
            frag[i] = 1;
            num[k] = i + 1;
            if (k == 1)
            {
                cnt++;
                int flg1, flg2;
                flg1 = flg2 = 0;
                for (j = n; j > 0; --j)
                {
                    if(num[j]!=q[n-j]){
                        flg1 = 1;
                        break;
                    }
                }
                for (j = n; j > 0;--j){
                    if (num[j] != p[n - j])
                    {
                        flg2 = 1;
                        break;
                    }
                }
                if(flg1==0){
                    qq = cnt;
                }
                if(flg2==0){
                    pp = cnt;
                }
            }
            else
            {
                fx(n, k - 1);
            }
            frag[i] = 0;
        }
    }
}

int int_comp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int lli_comp(const void*a,const void*b){return *(lli*)a-*(lli*)b;}
int main(void)
{

    int n;

    pp = qq = 0;
    scanf("%d", &n);
    for (int i = 0;i < n;i++) scanf("%d", &q[i]);
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);

    for (int i = 0; i < n; i++){
        num[i] = frag[i] = 0;
    }
    fx(n, n);
    printf("%lld\n", llabs(pp-qq));
    return 0;
}