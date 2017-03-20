// 思路同剑指offer - 030题，最小k个数 
#include <iostream>
#include <vector>
using namespace std;


void swap(vector<int>& nums, int i, int j) {
	int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int partition(vector<int>& nums, int lo, int hi) {
	int key = nums[hi];
	int i = lo - 1;

	for (int j = lo; j < hi; ++j) {
		if (nums[j] <= key) {
			i++;
			swap(nums, i, j);
		}
	}
	swap(nums, i + 1, hi);
	return i + 1;
}

vector<int> getBiggestNumbers(vector<int>& nums, int k) {
	vector<int> res;
	if (nums.size() <= 0 || nums.size() < k || k <= 0)
		return res;

	int start = 0, end = nums.size() - 1;
	int index = partition(nums, start, end);

	while (index != nums.size() - k) {
		if (index > nums.size() - k)
			end = index - 1;
		else
			start = index + 1;
		index = partition(nums, start, end);
	}

	for (int i = index; i < nums.size(); ++i)
		res.push_back(nums[i]);
	return res;
}



void main() {

	vector<int> nums;
	vector<int> res;

	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(1);
	nums.push_back(6);
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(3);
	nums.push_back(8);
	
	res = getBiggestNumbers(nums, 5);

	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
		
}
