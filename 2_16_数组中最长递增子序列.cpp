#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int longestSubArray(vector<int>& nums) {
	int* LIS = new int[nums.size()];
	for (int i = 0; i < nums.size(); i++) {
		LIS[i] = 1;
		for (int j = 0; j < i; j++) 
			if (nums[i] > nums[j] && LIS[j] + 1 > LIS[i])
				LIS[i] = LIS[j] + 1;
	}
	
	int maxRes = LIS[0];
	for (int i = 1; i < nums.size(); i++) {
		maxRes = max(maxRes, LIS[i]);
	}
	return maxRes;
}

void test1() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(-3);
	nums.push_back(4);
	nums.push_back(-5);
	nums.push_back(6);
	nums.push_back(-7);
	cout << longestSubArray(nums) << endl;
}

void main() {
	test1();
}