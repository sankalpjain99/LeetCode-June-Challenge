class Solution {
public:
        
    int Helper(int m,int n,int** dp){
        if(m<=0 || n<=0)
            return 0;
        if(m==1 && n==1)
            return 1;
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        int f = Helper(m-1,n,dp);
        int s = Helper(m,n-1,dp);
        dp[m][n] = f+s;
        return dp[m][n];
    }
    
    int uniquePaths(int m, int n) {
        
        int** dp = new int*[m+1];
        for(int i=0;i<=m;i++)
            dp[i] = new int[n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++)
                dp[i][j]=-1;
        }
        return Helper(m,n,dp);
    }
};