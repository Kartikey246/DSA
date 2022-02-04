class Solution {
private:
    int m,t;
    vector<int> dp;
    bool game(int mask,int score){
        if(dp[mask]!=-1) return dp[mask];
        for(int i=0;i<m;i++)
        {
            int cmask = 1<<i;
            if( (mask&cmask) == 0 )
                    if(score+i+1 >= t or game((mask|cmask),score+i+1)==false ) return dp[mask]=1;
        }
        return dp[mask]=0;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        m=maxChoosableInteger;
        t=desiredTotal;
        if((m*(m+1))/2 < t) return false;
        dp.resize(1<<m,-1);
        return game(0,0);
    }
};
/*
In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. The player who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.

Given two integers maxChoosableInteger and desiredTotal, return true if the first player to move can force a win, otherwise, return false. Assume both players play optimally.
*/
