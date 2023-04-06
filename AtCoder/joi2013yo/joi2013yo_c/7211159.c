// detail: https://atcoder.jp/contests/joi2013yo/submissions/7211159
#include<stdio.h>
#include<string.h>
typedef long long int ll;
int main(void)
{
	int n;
	char name[26];
	char s[101][101];
	int jcnt, flg, cnt = 0, namelen, signlen;
	int check;

	scanf("%d", &n);
	scanf("%s", name);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	namelen = strlen(name);

	for (int i = 0; i < n; i++) {
		check = 0;
		for (int j = 0; s[i][j] != '\0'; j++) {

			if (check == 1)break;
			if (s[i][j] == name[0]) {
				//printf("a");
				for (int jj = j + 1; s[i][jj] != '\0'; jj++) {

					if (check == 1)break;
					if (s[i][jj] == name[1]) {
						//printf("b");
						
						jcnt = 2;
						flg = 0;
						signlen = strlen(s[i]);
						if (jj + (jj - j) >= signlen) {
							continue;
						}
						for (int jjj = jj + (jj - j); s[i][jjj] != '\0'; jjj += jj - j) {
							//printf("c");
							
							if (check == 1)break;
							if (s[i][jjj] != name[jcnt++]) {
								flg = 1;
								break;
							}
							if (jcnt >= namelen) {
								//printf("d");
								break;
							}
						}
						if (flg == 0 && check == 0 && jcnt == namelen) {
							check = 1;
							//printf("%d行目\n", i + 1);
							cnt++;
						}

					}
				}
			}

		}
	}
	printf("%d\n", cnt);
	return 0;
}