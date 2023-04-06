// detail: https://atcoder.jp/contests/exawizards2019/submissions/4768887
#include<stdio.h>
int main(void)
{
	int n;
	char s[101];
	int i, cor, cob;

	cor = cob = 0;
	scanf("%d", &n);
	scanf("%s", s);
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == 'R') {
			cor++;
		}
		else if(s[i] == 'B') {
			cob++;
		}
	}
	if (cor > cob) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}