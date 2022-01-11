class Solution {
	public int searchInsert(int[] nums, int target) {
		if(nums == null || nums.length == 0) return 0;
		
		int n = nums.length;
		int left = 0;
		int right = n - 1;
		while(left < right){
			int mid = left + (right - left)/2;
			
			if(nums[mid] == target) return mid;
			else if(nums[mid] > target) right = mid; // right could be the result
			else left = mid + 1; // mid + 1 could be the result
		}
		
		// 1 element left at the end
		// post-processing
		return nums[left] < target ? left + 1: left;
	}
}
