/*
O(N)
O(N)
*/

class Solution {
    public int rob(int[] nums) {
        
        int n = nums.length;
        int dp[] = new int[n];
        dp[0]=nums[0];
        if(n==1){
            return nums[0];
        }
        
        dp[1] = Math.max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++){
            dp[i] = Math.max(nums[i]+dp[i-2],dp[i-1]);
        }
        
        return dp[n-1];

    }
}



/*
O(N)

O(1)
*/


class Solution {
    public int rob(int[] nums) {
        if (nums.length == 0) return 0;
    int prev1 = 0;
    int prev2 = 0;
    for (int num : nums) {
        int tmp = prev1;
        prev1 = Math.max(prev2 + num, prev1);
        prev2 = tmp;
    }
    return prev1;
    }
}
