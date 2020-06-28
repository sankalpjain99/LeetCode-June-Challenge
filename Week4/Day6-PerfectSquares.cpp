class Solution {
public:
    
    int Helper(int max,int n,int* dp){
        if(n<=0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        int ans = INT_MAX;
        for(int i=max;i>=1;i--){
            if(i*i <= n){
                ans = min(ans,1+Helper(max,n-i*i,dp));
            }
        }
        dp[n]=ans;
        return ans;
    }
    
    int numSquares(int n) {
        int max = ceil(sqrt(n));
        int* dp = new int[n+1];
        for(int i=0;i<=n;i++)
            dp[i]=-1;
        return Helper(max,n,dp);
    }
};