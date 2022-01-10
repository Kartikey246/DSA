// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

class Solution {
    public boolean searchMatrix(int[][] matrix, int target)
    {        
        int m = matrix.length , n = matrix[0].length , left = 0 , right = m * n - 1 , mid ;
        if( m == 0 )
        {
            return false ;
        }
        while( left <= right )
        {
            mid = left + ( ( right - left ) >> 1 ) ;
            if( target == matrix[mid/n][mid%n] )
            {
                return true ;                
            }
            else if( target < matrix[mid/n][mid%n] )
            {
                right = mid - 1 ;
            }
            else
            {
                left = mid + 1 ;
            }
        }
        return false ;
    }
}
