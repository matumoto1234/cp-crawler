// detail: https://atcoder.jp/contests/agc034/submissions/5764788
#include<stdio.h>
int main(void)
{
  int n,a,b,c,d;
  char s[200001],temp[200001];
  int i;
  int aflag,bflag,aflag2,bfalg2;
  
  aflag=bfag=aflag2=bflag2=0;
  scanf("%d",&n);
  scanf("%d",&a);
  scanf("%d",&b);
  scanf("%d",&c);
  scanf("%d",&d);
  scanf("%s",s);
  s[a-1]='a';
  s[b-1]='b';
  for(i=0;i<n;i++){
    temp[i]=s[i];
    if(s[i]=='#'){
      if(s[i+1]=='#'){
        printf("No");
        return 0;
      }
    }
  }
  for(i=0;i<n;i++){
    if(s[i]=='b'){
      if(s[d-1]=='b'){
        bflag=1;
        break;
      }
      if(s[i+1]=='.'){
        s[i]='.';
        s[i+1]='b';
      }
      else if(s[i+2]=='.'){
        s[i]='.';
        s[i+2]='b';
      }
      else{
        goto next;
      }
    }
  }
  for(i=0;i<n;i++){
    if(s[i]=='a'){
      if(s[c-1]=='a'){
        aflag=1;
        break;
      }
      if(s[i+1]=='.'){
        s[i]='.';
        s[i+1]='a';
      }
      else if(s[i+2]=='.'){
        s[i]='.';
        s[i+2]='a';
      }
      else{
        goto next;
      }
    }
  }
  if(aflag==1&&bflag==1){
    printf("Yes");
    return 0;
  }
  next:
  for(i=0;i<n;i++){
    s[i]=temp;
  }
  for(i=0;i<n;i++){
    if(s[i]=='b'){
      if(s[i+1]=='.'){
        if(s[i-1]=='.'){
          break;
        }
        s[i]='.';
        s[i+1]='b';
      }
      else if(s[i+2]=='.'){
        s[i]='.';
        s[i+2]='b';
      }
      else if(s[d]=='b'){
        printf("No");
        return 0;
      }
    }
  }
  for(i=0;i<n;i++){
    if(s[i]=='a'){
      if(s[c-1]=='a'){
        aflag2=1;
        break;
      }
      if(s[i+1]=='.'){
        s[i]='.';
        s[i+1]='a';
      }
      else if(s[i+2]=='.'){
        s[i]='.';
        s[i+2]='a';
      }
      else{
        printf("No");
        return 0;
      }
    }
  }
  for(i=0;i<n;i++){
    if(s[i]=='b'){
      if(s[d-1]=='b'){
        bflag2=1;
        break;
      }
      if(s[i+1]=='.'){
        s[i]='.';
        s[i+1]='b';
      }
      else if(s[i+2]=='.'){
        s[i]='.';
        s[i+2]='b';
      }
      else{
        printf("No");
        return 0;
      }
    }
  }
  if(aflag==1&&bflag==1){
    printf("Yes");
  }
  return 0;
}