/*You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.*/


// Calculation minCost(i):

// If no trip on day i, then minCost(i) = minCost(i-1).
// minCost(i)=0 for all i ≤ 0.
// Otherwise:
// If a 1-day pass on day i. In this case, minCost(i) = minCost(i) + costs[0].
// If a 7-day pass ending on day i. then : In this case, minCost(i) = min(minCost(i − 7), minCost(i − 6), …, minCost(i − 1)) + costs[1].
// But since since minCost is increasing (adding a day never reduces the minCost) hence:
// minCost(i) = minCost(i − 7) + costs[2]

// Same case for 30-day pass also.


class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        boolean[] dayIncluded = new boolean[366];
        for (int day : days) {
            dayIncluded[day] = true;
        }
        int[] minCost = new int[366];
        minCost[0] = 0;
        for (int day = 1; day <= 365; ++day) {
            if (!dayIncluded[day]) {
                minCost[day] = minCost[day-1];
                continue;
            }
            int min;
            min = minCost[day-1] + costs[0];
            min =Math.min(min, minCost[Math.max(0, day-7)] + costs[1]);
            min = Math.min(min, minCost[Math.max(0, day-30)] + costs[2]);
            minCost[day] = min;
        }

        return minCost[365];

    }
}
