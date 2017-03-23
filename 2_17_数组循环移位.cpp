#include <iostream>
#include <vector>
using namespace std;

void reverseArr(vector<char>& nums, int from, int to) {
	while (from < to) {
		char temp = nums[from];
		nums[from] = nums[to];
		nums[to] = temp;
		from++;
		to--;
	}
}

void rightShift(vector<char>& nums, int k) {
	k %= nums.size();
	reverseArr(nums, 0, nums.size() - k - 1);
	reverseArr(nums, nums.size() - k, nums.size() - 1);
	reverseArr(nums, 0, nums.size() - 1);
}


void test1() {
	vector<char> nums;
	nums.push_back('1');
	nums.push_back('2');
	nums.push_back('3');
	nums.push_back('4');
	nums.push_back('a');
	nums.push_back('b');
	nums.push_back('c');
	nums.push_back('d');

	for (char c : nums) 
		cout << c << " ";
	cout << endl;
	rightShift(nums, 5);
	for (char c : nums) 
		cout << c << " ";
}

void main() {
	test1();
}