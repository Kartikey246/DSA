// C++ program to count the
// no. of ways to place 2*1 size
// tiles in 2*n size board.


// Let “count(n)” be the count of ways to place tiles on a “2 x n” grid, we have following two ways to place first tile. 
// 1) If we place first tile vertically, the problem reduces to “count(n-1)” 
// 2) If we place first tile horizontally, we have to place second tile also horizontally. So the problem reduces to “count(n-2)” 
// Therefore, count(n) can be written as below. 

//    count(n) = n if n = 1 or n = 2
//    count(n) = count(n-1) + count(n-2)
// Here’s the code for the above approach:


int getNoOfWays(int n)
{
    // Base case
    if (n <= 2)
      return n;

    return getNoOfWays(n - 1) + getNoOfWays(n - 2);
}
