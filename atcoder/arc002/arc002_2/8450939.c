// detail: https://atcoder.jp/contests/arc002/submissions/8450939
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
  int y,m,d;
  char s[20];
  
  scanf("%s",s);
  y=atoi(s);
  m=atoi(&s[5]);
  d=atoi(&s[8]);
  //printf("%d %d %d\n",y,m,d);
  int flg=0;
  if(y%4==0){
    flg=1;
    if(y%100==0){
        flg=0;
    }
    if(y%400==0){
        flg=1;
    }
   }
    else{
      flg=0;
    }
  for(int j=m;j<=12;j++){
      if(j==m){
          for(int k=d;k<=31;k++){
        if(flg==1&&j==2&&k==29){
          if(y%(j*k)==0){
            sprintf(s,"%d/%02d/%02d",y,j,k);
            printf("%s\n",s);
            return 0;
            }
        }
        if(j==2&&k==29){
          break;
        }
        if(j<=7&&j%2==0&&k==31){
          break;
        }
        if(j>=8&&j%2!=0&&k==31){
          break;
        }
        //printf(">>%d %d %d\n",y,j,k);
        if(y%(j*k)==0){
          sprintf(s,"%d/%02d/%02d",y,j,k);
          printf("%s\n",s);
          return 0;
        }
      }
      }
      else {
          for(int k=1;k<=31;k++){
        if(flg==1&&j==2&&k==29){
          if(y%(j*k)==0){
            sprintf(s,"%d/%02d/%02d",y,j,k);
            printf("%s\n",s);
            return 0;
            }
        }
        if(j==2&&k==29){
          break;
        }
        if(j<=7&&j%2==0&&k==31){
          break;
        }
        if(j>=8&&j%2!=0&&k==31){
          break;
        }
        //printf(">>%d %d %d\n",y,j,k);
        if(y%(j*k)==0){
          sprintf(s,"%d/%02d/%02d",y,j,k);
          printf("%s\n",s);
          return 0;
        }
      }
      }
    }
  
  for(int i=y+1;i<=3001;i++){
    flg=0;
    if(i%4==0){
      flg=1;
      if(i%100==0){
        flg=0;
      }
      if(i%400==0){
        flg=1;
      }
    }
    for(int j=1;j<=12;j++){
      for(int k=1;k<=31;k++){
        if(flg==1&&j==2&&k==29){
          if(i%(j*k)==0){
            sprintf(s,"%d/%02d/%02d",i,j,k);
            printf("%s\n",s);
            return 0;
            }
        }
        if(j==2&&k==29){
          break;
        }
        if(j<=7&&j%2==0&&k==31){
          break;
        }
        if(j>=8&&j%2!=0&&k==31){
          break;
        }
        if(i%(j*k)==0){
          sprintf(s,"%d/%02d/%02d",i,j,k);
          printf("%s\n",s);
          return 0;
        }
      }
    }
    return 0;
  }
}
