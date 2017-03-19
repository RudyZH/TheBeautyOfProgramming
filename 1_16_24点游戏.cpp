#include <iostream>
#include <string>
#include <math.h>

const double Threshold = 1E-6;
const int CardsNumber = 4;
const int ResultValue = 24;
double number[CardsNumber];
std::string result[CardsNumber];

bool pointsGame(int n) {

	if (n == 1) {
		if (fabs(number[0] - ResultValue) < Threshold) {
			std::cout << result[0] << std::endl;
			return true;
		} else 
			return false;
	}

	for (int i = 0; i < n; i++)	{
		for (int j = i + 1; j < n; j++) {
			double a, b;
			std::string expa, expb;

			a = number[i];
			b = number[j];
			number[j] = number[n - 1];

			expa = result[i];
			expb = result[j];
			result[j] = result[n - 1];

			result[i] = '(' + expa + '+' + expb + ')';
			number[i] = a + b;
			if (pointsGame(n - 1))
				return true;

			result[i] = '(' + expa + '-' + expb + ')';
			number[i] = a - b;
			if (pointsGame(n - 1))
				return true;

			result[i] = '(' + expb + '-' + expa + ')';
			number[i] = b - a;
			if (pointsGame(n - 1))
				return true;

			result[i] = '(' + expa + '*' + expb + ')';
			number[i] = a * b;
			if (pointsGame(n - 1))
				return true;

			if (b != 0) {
				result[i] = '(' + expa + '/' + expb + ')';
				number[i] = a / b;
				if (pointsGame(n - 1))
					return true;
			}
			if (a != 0) {
				result[i] = '(' + expb + '/' + expa + ')';
				number[i] = b / a;
				if (pointsGame(n - 1))
					return true;
			}
			number[i] = a;
			number[j] = b;
			result[i] = expa;
			result[j] = expb;
		}
	}
	return false;
}

int main() {
	int x;

	number[0] = 5;
	number[1] = 8;
	number[2] = 3;
	number[3] = 11;

	result[0] = "5";
	result[1] = "8";
	result[2] = "3";
	result[3] = "11";

	if(pointsGame(4)) 
		std::cout << "success" << std::endl;
	else 
		std::cout << "fail" << std::endl;
	return 0;
}
