// detail: https://atcoder.jp/contests/abc120/submissions/4453674
int main(void)
{
	int a, b, k,yaku[100],su;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &k);
	int i,co=0;
	for (i = 1; i <= 100; i++) {
		if (a%i == 0) {
			if (b%i == 0) {
				yaku[co]=i;
				co++;
			}
		}
	}
	su = yaku[k-1];
	printf("%d\n", a);
	return 0;
}