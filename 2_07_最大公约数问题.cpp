#include <iostream>
using namespace std;

int gcd_1(int x, int y) {
	return (!y) ? x : gcd_1(y, (x % y));
}

int gcd_2(int x, int y) {
	if (x < y)
		return gcd_2(y, x);
	if (y == 0)
		return x;
	else 
		return gcd_2(x - y, y);
}

// best O(n) = log(max(x, y))
int gcd_3(int x, int y) {
	if (x < y)
		return gcd_3(y, x);
	if (y == 0)
		return x;
	else {
		if (x % 2 == 0) {
			if (y  % 2 == 0)
				return (gcd_3(x >> 1, y >> 1) << 1);
			else 
				return gcd_3(x >> 1, y);
		} else {
			if (y % 2 == 0)
				return gcd_3(x, y >> 1);
			else 
				return gcd_3(x - y, y);
		}
	}
}


void test1() {
	int x = 42, y = 30;
	cout << gcd_1(x, y) << endl;
}

void test2() {
	int x = 42, y = 30;
	cout << gcd_2(x, y) << endl;
}

void test3() {
	int x = 420, y = 300;
	cout << gcd_3(x, y) << endl;
}

void main() {
	test3();
}