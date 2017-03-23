#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
	int maxEndinghere = nums[0];
	int maxSoFar = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		maxEndinghere = max(nums[i], nums[i] + maxEndinghere);
		maxSoFar = max(maxSoFar, maxEndinghere);
	}
	return maxSoFar;
}

void test1() {
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(-2);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(-1);
	nums.push_back(2);
	//nums.push_back(6);
	cout << maxSubArray(nums) << endl;
}

void main() {
	test1();
}