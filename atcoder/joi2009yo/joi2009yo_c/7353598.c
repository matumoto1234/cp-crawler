// detail: https://atcoder.jp/contests/joi2009yo/submissions/7353598
#include<stdio.h>
#include<string.h>
int serch(char, int);//色と添え字
int ue(char, int);//色と添え字
int sita(char, int);//色と添え字
int end(char*);//char型配列

char a[10000];
int n;
int main(void)
{
    int min,ent1,ent2;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf(" %c",&a[i]);
    }
    min=serch(a[1],0);
    ent1=serch(a[n-2],n-1);
    if(min>ent1){
        min=ent1;
    }
    for(int i=1;i<n-1;i++){
        ent1=serch(a[i+1],i);
        ent2=serch(a[i-1],i);
        if(ent1<min){
            min=ent1;
        }
        if(ent2<min){
            min=ent2;
        }
    }
    printf("%d\n",min);
    return 0;
}

int serch(char c, int x)
{
    int uen,sitan;
    
    uen=ue(c,x);
    sitan=sita(c,x);
    //printf("ue>%d sita>%d\n",uen,sitan);
    int tmp=n;
    if(uen+sitan>=3){
        char dat[10000];
        strcpy(dat,a);
        for(int i=x+uen+1;i<n;i++){
            dat[x-sitan++]=dat[i];
        }
        tmp=end(dat);
    }
    return tmp;
}

/*最後までやって残った要素の数を返す*/
int end(char *dat)
{
    int len,cnt=0;

    len=strlen(dat);
    for(int i=0;i<len;i++){
        if(dat[i]==dat[i+1]){
            cnt++;
        }
        else{
            if(cnt>=4){
                int ji=i-cnt;
                for(int j=i+1;j<n;j++){
                    dat[ji++]=dat[j];
                }
                dat[ji]='\0';
            }
            cnt=0;
        }
    }
    len=strlen(dat);
    cnt=0;
    for(int i=0;i<n;i++){
        if(dat[i]==dat[i+1]){
            cnt++;
        }
        else{
            if(cnt>=4){
                end(dat);
            }
            else{
                cnt=0;
            }
        }
    }
    return len;
}

/*上にある同じ文字の数を返す*/
int ue(char c, int x)
{
    int cnt=0;
    for(int i=x+1;c==a[i]&&i<n;i++){
        cnt++;
    }
    return cnt;
}
/*下にある同じ文字の数を返す*/
int sita(char c, int x)
{
    int cnt=0;
    for(int i=x-1;c==a[i]&&i>=0;i--){
        cnt++;
    }
    return cnt;
}