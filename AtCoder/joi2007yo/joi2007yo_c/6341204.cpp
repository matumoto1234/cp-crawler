// detail: https://atcoder.jp/contests/joi2007yo/submissions/6341204
#include<stdio.h>
#include<string.h>
int main(void)
{
	char s[1001],temp[1001];
	int len,i;
	
	scanf("%s",s);
	len=strlen(s);
	for(i=0;i<len;i++){
		if(s[i]>='D'&&s[i]<='Z'){
			s[i]=s[i]-('D'-'A');
		}
		else if(s[i]>='A'&&s[i]<='C'){
			s[i]=s[i]+('W'-'A');
		}
	}
	printf("%s\n",s);
	return 0;
}