#include <fstream>
#include <iostream>
#include <time.h>
using std::cin;
using std::cout;
using std::endl;
int Random(int min, int max) {
	if (min > max) {
		int b = max;
		max = min;
		min = b;
	}
	srand(time(NULL));
	return min + rand() % (max - min);
}
int ost(int s, int y, int m, int d, int n, int num) {
	int i;
	if (num == 11) { i = 14; }
	else if (num == 10) { i = 13; }
	int k = 0;
	while (n > 0) {
		int b = n % 10;
		k += b * (i--);
		n = (int)(n / 10);
	}
	while (d > 0) {
		int b = d % 10;
		k += b * (i--);
		d = (int)(d / 10);
	}
	while (m > 0) {
		int b = m % 10;
		k += b * (i--);
		m = (int)(m / 10);
	}
	while (y > 0) {
		int b = y % 10;
		k += b * (i--);
		y = (int)(y / 10);
	}
	k += s;
	int ans = -1;
	for (int C = 0; C < 10; C++) {
		if (num == 11) {
			if ((k + 15 * C) % 11 == 0) { ans = C; }
		}
		else if (num == 10) {
			if ((k + 14 * C) % 10 == 0) { ans = C; }
		}
	}
	return ans;
}