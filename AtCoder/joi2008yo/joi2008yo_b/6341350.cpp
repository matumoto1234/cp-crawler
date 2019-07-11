// detail: https://atcoder.jp/contests/joi2008yo/submissions/6341350
#include<stdio.h>
#include<string.h>
int main(void)
{
	int i,j,start,jco,ico;
	char s[10001];
	char joi[4]="JOI",ioi[4]="IOI";
	
	jco=ico=0;
	scanf("%s",s);
	for(i=0;s[i]!='\0';i++){
		if(s[i]=='J'){
			start=i;
			for(j=0;j<3;j++){
				if(s[i]==joi[j]){
					i++;
				}
			}
			if(i-start==3){
				jco++;
			}
			i=start;
		}
		if(s[i]=='I'){
			start=i;
			for(j=0;j<3;j++){
				if(s[i]==ioi[j]){
					i++;
				}
			}
			if(i-start==3){
				ico++;
			}
			i=start;
		}
	}
	printf("%d\n%d\n",jco,ico);
	return 0;
}