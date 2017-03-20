// һ��������ĳ�������ִ�������һ�룬�ҳ�������
// ��ͬ�ڽ�ָoffer - 029��

//����ԭ���ڱ��������ʱ�򱣴�����ֵ��һ���������е�һ�����֣�
//һ���Ǵ����������Ǳ�������һ�����ֵ�ʱ�������һ�����ֺ�����
//֮ǰ�����������ͬ���������1�������һ�����ֺ�����֮ǰ�������
//�ֲ�ͬ���������1���������Ϊ�㣬������Ҫ������һ�����֣����Ѵ�
//����Ϊ1����������Ҫ�ҵ����ֳ��ֵĴ����������������ֳ��ֵĴ���֮
//�ͻ�Ҫ�࣬��ôҪ�ҵ����ֿ϶������һ�ΰѴ�����Ϊ1ʱ��Ӧ�����֡�

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