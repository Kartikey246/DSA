// The goal is to keep track of:

// Maximum So far and add it to the cur_cell and maintain maximum result
// Here, max_so_far contains : A[i] + i
// Original Given Formula : A[i] + A[j] + i - j

// Break in two parts : A[i] + i and A[j] -j
// Keep MAX_VALUE of first part among the elements seen so far
// Add the current element to max_so_far and check the result is changing or not
// Also, keep updating the max_so_far at each step
// Java

class Solution {
    public int maxScoreSightseeingPair(int[] a) {
        int max_so_far = a[0];
        int result = 0;
        for(int i=1;i<a.length;i++){
            result = Math.max(result, max_so_far + a[i] - i);
            max_so_far = Math.max(max_so_far, a[i] + i);
        }   
        return result;
    }
}
