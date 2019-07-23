// detail: https://atcoder.jp/contests/joi2009yo/submissions/6514789
#include<stdio.h>
int main(void)
{
	int ahi, ami, asi, aho, amo, aso;
	int bhi, bmi, bsi, bho, bmo, bso;
	int chi, cmi, csi, cho, cmo, cso;
	int ah, am, as, bh, bm, bs, ch, cm, cs;
	int sumi, sumo, sa;

	ah = am = as = bh = bm = bs = ch = cm = cs = 0;
	scanf("%d %d %d %d %d %d", &ahi, &ami, &asi, &aho, &amo, &aso);
	scanf("%d %d %d %d %d %d", &bhi, &bmi, &bsi, &bho, &bmo, &bso);
	scanf("%d %d %d %d %d %d", &chi, &cmi, &csi, &cho, &cmo, &cso);
	sumi = ahi * 3600 + ami * 60 + asi;
	sumo = aho * 3600 + amo * 60 + aso;

	sa = sumo - sumi;
	if (sa >= 3600) {
		ah = sa / 3600;
		sa = sa - 3600 * ah;
	}
	if (sa >= 60) {
		am = sa / 60;
		sa = sa - 60 * am;
	}
	if (sa >= 1) {
		as = sa;
	}
	printf("%d %d %d\n", ah, am, as);
	sumi = bhi * 3600 + bmi * 60 + bsi;
	sumo = bho * 3600 + bmo * 60 + bso;

	sa = sumo - sumi;
	if (sa >= 3600) {
		bh = sa / 3600;
		sa = sa - 3600 * bh;
	}
	if (sa >= 60) {
		bm = sa / 60;
		sa = sa - 60 * bm;
	}
	if (sa >= 1) {
		bs = sa;
	}
	printf("%d %d %d\n", bh, bm, bs);
	sumi = chi * 3600 + cmi * 60 + csi;
	sumo = cho * 3600 + cmo * 60 + cso;

	sa = sumo - sumi;
	if (sa >= 3600) {
		ch = sa / 3600;
		sa = sa - 3600 * ch;
	}
	if (sa >= 60) {
		cm = sa / 60;
		sa = sa - 60 * cm;
	}
	if (sa >= 1) {
		cs = sa;
	}
	printf("%d %d %d\n", ch, cm, cs);
	return 0;
}