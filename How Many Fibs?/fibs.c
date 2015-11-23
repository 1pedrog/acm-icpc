#include <stdio.h>
#include <string.h>

int lessThan(char *a, char *b, int la, int lb) {
	int i;
	if (la < lb) {
		return 1;
	}
	if (la > lb) {
		return 0;
	}
	for (i = la - 1; i >= 0; i--) {
		if (a[i] < b[i]) {
			return 1;
		} else if (a[i] > b[i]) {
			return 0;
		}
	}
	return 2;
}

void add(char *c, char *a, char *b, int *lc, int la, int lb) {
	int i, lr, ci, co;
	char r[100];
	lr = la + 1;
	for (i = 0, ci = 0; i < lb; i++) {
		r[i] = a[i] + b[i];
		co = (r[i] >= 10);
		r[i] = r[i] % 10;
		if (ci) {
			r[i] = (r[i] + 1) % 10;
			co = co | (r[i] == 0);
		}
		ci = co;
	}
	for (; i < la; i++) {
		r[i] = (a[i] + ci) % 10;
		ci = (r[i] == 0);
	}
	if (ci) {
		r[i] = 1;
	} else {
		lr--;
	}
	for (i = 0; i < lr; i++) {
		c[i] = r[i];
	}
	*lc = lr;
}

void subtract(char *c, char *a, char *b, int *lc, int la, int lb) {
	int i, bi, bo, lr;
	char r[100];
	lr = la;
	for (i = 0, bi = 0; i < lb; i++) {
		r[i] = a[i] - b[i];
		if (bi) {
			r[i]--;
		}
		bo = (r[i] < 0);
		if (bo) {
			r[i] += 10;
		}
		bi = bo;
	}
	for (; i < la; i++) {
		r[i] = a[i] - bi;
		bi = (a[i] < 0);
		if (bi) {
			r[i] += 10;
		}
	}
	for (i = 0; i < lr; i++) {
		c[i] = r[i];
	}
	*lc = lr;
	while (c[*lc - 1] == 0) {
		(*lc)--;
	}
}

int main(int argc, char **argv) {
	int i, n, la, lb, lf0, lf1, tmp;
	char *a, *b, f0[100], f1[100];
	while (scanf("%s %s", a, b) != EOF) {
		if (a[0] == b[0] && a[0] == '0') {
			return 0;
		}
		la = strlen(a);
		lb = strlen(b);
		if (la == 1 && (a[0] == '0' || a[0] == '1')) {
			n = 1;
		} else {
			n = 0;
		}
		for (i = 0; i < 100; i++) {
			f0[i] = f1[i] = 0;
		}
		f0[0] = lf0 = lf1 = 1;
		f1[0] = 2;
		for (i = 0; i < la / 2; i++) {
			tmp = a[i] - 48;
			a[i] = a[la - i - 1] - 48;
			a[la - i - 1] = tmp;
		}
		for (i = 0; i < lb / 2; i++) {
			tmp = b[i] - 48;
			b[i] = b[lb - i - 1] - 48;
			b[lb - i - 1] = tmp;
		}
		while (lessThan(f1, a, lf1, la) == 1) {
			add(f1, f1, f0, &lf1, lf1, lf0);
			subtract(f0, f1, f0, &lf0, lf1, lf0);
		}
		while (lessThan(f1, b, lf1, lb)) {
			n++;
			add(f1, f1, f0, &lf1, lf1, lf0);
			subtract(f0, f1, f0, &lf0, lf1, lf0);
		}
		printf("%i\n", n);
	}
	return 0;
}
