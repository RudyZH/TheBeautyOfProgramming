#include <stdio.h>
#include <windows.h>
// http://bbs.csdn.net/topics/330120699

#define HALF_BITS_LENGTH 4
#define FULLMASK 255
#define LMASK (FULLMASK << HALF_BITS_LENGTH)
#define RMASK (FULLMASK >> HALF_BITS_LENGTH)
#define RSET(b, n) (b = ((LMASK & b) | (n)))
#define LSET(b, n) (b = ((RMASK & b) | ((n) << HALF_BITS_LENGTH)))
#define RGET(b) (RMASK & b)
#define LGET(b) ((LMASK & b) >> HALF_BITS_LENGTH)
#define GRIDW 3

// 1-6
void one_six() {
	unsigned char b;
	for (LSET(b, 1); LGET(b) <= GRIDW * GRIDW; LSET(b, (LGET(b) + 1)))
		for (RSET(b, 1); RGET(b) <= GRIDW * GRIDW; RSET(b, (RGET(b) + 1)))
			if (LGET(b) % GRIDW != RGET(b) % GRIDW)
				printf("A = %d, B = %d\n", LGET(b), RGET(b));
}

// 1-7
void one_seven() {
	BYTE i = 81;
	while (i--) {
		if (i / 9 % 3 == i % 9 % 3)
			continue;
		printf("A = %d, B = %d\n", i / 9 + 1, i % 9 + 1);
	}
}

// 1-8
struct {
	unsigned char a:4;
	unsigned char b:4;
} i;

void one_eight() {
	for (i.a = 1; i.a <= 9; i.a++) 
		for (i.b = 1; i.b <= 9; i.b++)
			if (i.a % 3 != i.b % 3)
				printf ("A = %d, B = %d\n", i.a, i.b);
}

int main() {
	one_eight();

	return 0;
}
