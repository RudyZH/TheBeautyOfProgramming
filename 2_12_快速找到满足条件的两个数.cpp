package leetCode;

import java.util.HashMap;
import java.util.Map;

public class twoNum {

	public int[] twoSum(int[] nums, int target) {
		int[] results = new int[2];
		Map<Integer, Integer> hash = new HashMap<Integer, Integer>();
		
		for(int i = 0; i < nums.length; i++) {
			
			int anOther = target - nums[i];
			
			if(hash.containsKey(anOther)) {
				results[0] = hash.get(anOther);
				results[1] = i;
			}			
			hash.put(nums[i], i);
		}		
		return results;
	}
	
	public static void main(String[] args) {
		
		twoNum t = new twoNum();
		int[] nums = new int[4];
		nums[0] = 2;
		nums[1] = 7;
		nums[2] = 11;
		nums[3] = 15;
		
		int target = 26;
		
		int[] res = new int[2];
		res = t.twoSum(nums, target);
		System.out.println(res[0]);
		System.out.println(res[1]);
	}
	
}


// 方法 2
//先排序， 在查找 O(nlogn)

for (int i = 0, j = n - 1; i < j) {
	if (a[i] + a[j] == sum)
		return (i, j);
	else if (a[i] + a[j] < sum)
		i++;
	else j--;
}
return (-1, -1)
