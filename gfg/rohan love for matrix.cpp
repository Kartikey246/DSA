class Solution {
  public:
  int mod =1000000007;
    int firstElement(int n) 
    {
        if(n==1 || n==2)
        {
            return 1;
        }
        
        int a=1;
        int b=1;
        for(int i=3;i<=n;i++)
        {
            int c=1;
            int d=1;
            int e=1;
            int f=0;
           int x = ((a*c)%mod) + ((b*d)%mod);
           int y = ((a*e)%mod) + ((b*f)%mod);
            a =x%mod;
            b =y%mod;
        }
        return a;
    }
};
