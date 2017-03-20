#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <math.h>


using namespace std;


// 1-1
//int main() {
//	
//	for (; ;) {
//		for (int i = 0; i < 9600000; i++)
//			;
//		Sleep(10);
//	}
//	return 0;
//}


// 1-2
//int main() {
//	const DWORD busyTime = 10;
//	const DWORD idleTime = busyTime;
//
//	INT64 startTime = 0;
//	while (true) {
//		DWORD startTime = GetTickCount();
//		while ((GetTickCount() - startTime) <= busyTime)
//			;
//		Sleep(idleTime);
//	}
//	return 0;
//}


// 1-4
const int SAMPLING_COUNT = 200;
const double PI = 3.14159265358;
const int TOTAL_AMPLITUDE = 300;

int main() {
	DWORD busySpan[SAMPLING_COUNT];
	int amplitude = TOTAL_AMPLITUDE / 2;
	double radian = 0.0;
	double radianIncrement = 2.0 / (double)SAMPLING_COUNT;
	for (int i = 0; i < SAMPLING_COUNT; i++) {
		busySpan[i] = (DWORD)(amplitude + (sin(PI * radian) * amplitude));
		radian += radianIncrement;
	}
	DWORD startTime = 0;
	for (int j = 0; ;j = (j + 1) % SAMPLING_COUNT) {
		startTime = GetTickCount();
		while ((GetTickCount() - startTime) <= busySpan[j])
			;
		Sleep(TOTAL_AMPLITUDE - busySpan[j]);
	}
	return 0;
}
