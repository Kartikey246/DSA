//can be thought as 0-1 Knapsack Problem recursive solution

int ways(int A[],int X,int n)
{
    if(X==0) return 1;
    if(n==0) return 0;
    
    if(A[n-1]<=X)
    {
        return ways(A,X-A[n-1],n-1)+ways(A,X,n-1);
    }
    else return ways(A,X,n-1);
}
//DP solution

int dpways(int coins[],int n,int s)
{    
    int dp[s+1][n+1];
    
    for(int i=0;i<=n;i++) dp[0][i] = 0;
    for(int i=0;i<=s;i++) dp[i][0] = 1;
    
    for(int i=1;i<=s;i++)
    {
        for(int j=1;j<=n;j++)
        {
            
            if(coins[i-1]<=j)
            {
                dp[i][j] = dp[i-1][j-coins[i-1]]+dp[i-1][j];
            }
            else
                dp[i][j] = dp[i-1][j];
            
        }
    }
    return dp[s][n];

}
//Caller function

int powerSum(int X, int N) 
{
    int k = pow(X,1.0/N);
    cout<<"K = "<<k<<endl;
    int A[k];
    for(int i=1;i<=k;i++)
    {
        A[i-1] = pow(i,N);
    }
		 int res = ways(A,X,k);
     return res;
}
int res = ways(A,X,k);
return res;
}

