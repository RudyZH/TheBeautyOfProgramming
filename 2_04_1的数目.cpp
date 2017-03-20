#include <iostream>
using namespace std;

int numberOfOnes(int n) {
	int count = 0;
	int i = 1;
	int current = 0, high = 0, low = 0;

	while ((n / i) != 0) {
		current = (n / i) % 10;
		high = n / (i * 10);
		low = n % i;

		if (current == 0) 
			count += (high * i);
		else if (current == 1) 
			count += (high * i + low + 1);
		else 
			count += ((high + 1) * i);

		i *= 10;
	}

	return count;
}

int main() {

	cout << numberOfOnes(93) << endl;
}
