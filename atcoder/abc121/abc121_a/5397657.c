// detail: https://atcoder.jp/contests/abc121/submissions/5397657
#include<stdio.h>
int main(void)
{
	int H , W;
	int h, w;
	int ansx, ansy;
	
	scanf("%d",&H);
	scanf("%d",&W);
	scanf("%d",&h);
	scanf("%d",&w);
	ansx = H-h;
	ansy = W-w;
	printf("%d\n",ansx*ansy);
	return 0;
}