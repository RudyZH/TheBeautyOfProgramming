#include <iostream>
using namespace std;


/*
问题1：求 N! 结尾0的个数
*/

// 方法 1
// 若 N! = K * 10^M, 且K不能被10整除，那么N!末尾有M个0，再考虑
// 对 N! 进行质因数分解，N! = (2^x) * (3^y) * (5^z)...，由于
// 10 = 2 * 5，所以 M 只跟 X 和 Z 相关，于是 M = min(X, Z)，
// X >= Z，因为能被2整除的数出现频率高于被5整除的数，所以 M = Z.
int numOfZeroes(int n) {
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (j % 5 == 0) {
			res++;
			j /= 5;
		}
	}
	return res;
}

// 方法 2
// Z = [N/5] + [N/25] + [N/125] + ..., 存在一个k，使得 5^k > N
// [N/5^k] = 0. 公式中，[N/5]表示不大于N的数中5的倍数贡献一个5， 
// [N/25]，表示不大于N的数中5^2的倍数再贡献一个5...
int numOfZeroes2(int n) {
	int res = 0;
	while (n) {
		res += n / 5;
		n /= 5;
	}
	return res;
}

/////////////////////////////////////////////////////////////////////////////

/*
问题2：求 N! 二进制表示中最低位 1 的位置
*/

// 方法 1
// 一个二进制数除以2的计算过程：
// 判断最后一个二进制位是否为0，若为0，则将此二进制数右移一位，即为商值，
// 反之，若为1，则说明这个二进制数是奇数，无法被2整除。
// 所以，这个问题实际上等同于求 N! 含有质因子 2 的个数。答案等于其个数 + 1;
// [N/2] + [N/4] + [N/8] + ...
int lowestOne(int n) {
	int res = 0;
	while (n) {
		n >> 1;
		res += n;
	}
	return res + 1;
}

// 方法 2
// N! 含有质因数2的个数，还等于 N 减去 N 的2进制表示中1的数目
// Example：
// N = 11011
// [N/2] + [N/4] + [N/8] + ...
//   1101 + 110 + 11 + 1
// = (1000 + 100 + 1) +
//   (100 + 10) +
//   (10 + 1) + 
//	  1
// = (1000 + 100 + 10 + 1) + (100 + 10 + 1) + 1
// = 1111 + 111 + 1
// = (10000 - 1) + (1000 - 1) + (10 - 1) + (1 - 1)
// = 11011 - (N二进制表示中1的个数)

int main() {
	cout << numOfZeroes2(1000) << endl;
}
