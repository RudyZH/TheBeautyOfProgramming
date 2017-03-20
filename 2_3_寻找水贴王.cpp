// 一组数字中某个数出现次数超过一半，找出该数字
// 等同于剑指offer - 029题

//消除原理：在遍历数组的时候保存两个值：一个是数组中的一个数字，
//一个是次数。当我们遍历到下一个数字的时候，如果下一个数字和我们
//之前保存的数字相同，则次数加1。如果下一个数字和我们之前保存的数
//字不同，则次数减1。如果次数为零，我们需要保存下一个数字，并把次
//数设为1。由于我们要找的数字出现的次数比其他所有数字出现的次数之
//和还要多，那么要找的数字肯定是最后一次把次数设为1时对应的数字。

#include <iostream>
#include <vector>

using namespace std;


bool checkMoreThanHalf(vector<int>& nums, int res) {
	int times = 0;
	for (int i : nums)
		if (i == res)
			times++;

	if (times * 2 <= nums.size())
		return false;
	else 
		return true;
}

int moreThanHalfNum(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	int res = nums[0];
	int times = 1;

	for (int i = 1; i < nums.size(); i++) {
		if (times == 0) {
			res = nums[i];
			times = 1;
		} else if (nums[i] == res)
			times++;
		else times--;
	}

	if (!checkMoreThanHalf(nums, res))
		res = 0;
	return res;
}



int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(5);
	nums.push_back(4);
	nums.push_back(2);

    cout << moreThanHalfNum(nums);

	return 0;
}