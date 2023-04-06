// detail: https://atcoder.jp/contests/joi2013yo/submissions/7211694
#include<stdio.h>
#include<string.h>
int main(void) {
	int n;
	char name[10000], kanban[1000][1000];
	int longname, len1[1000];

	scanf("%d", &n);
	scanf("%s", name);
	longname = strlen(name);
	for (int i = 0; i < n; i++) {
		scanf("%s", kanban[i]);
		len1[i] = strlen(kanban[i]);
	}

	int h;
	int cnt = 0;
	int z = 0;
	int flg;
	for (int i = 0; i < n; i++) {
		for (int j = 0; kanban[i][j] != '\0'; j++) {
			if (kanban[i][j] == name[0]) {
				for (int k = j + 1; kanban[i][k] != '\0'; k++) {
					if (kanban[i][k] == name[1]) {
						flg = 0;
						z = 1;
						for (int l = k; l < len1[i] && z < longname; l+=k-j) {
							if (kanban[i][l] == name[z]) {
								z++;
							}
							else {
								flg = 1;
								break;
							}
						}
						if (flg == 0 && z == longname) {
							printf("%d行目\n", i + 1);
							cnt++;
							goto next;
						}
					}
				}
			}
		}
	next:;
	}

	printf("%d\n", cnt);
	return 0;
}
