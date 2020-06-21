class Solution {
public:
    
    #define ll long long int
    
    ll Helper(int i,int j,vector<vector<int>>& d,int n,int m,int** dp){
        if(i==n-1 && j==m-1){
            if(d[i][j]>=0)
                return -1*d[i][j];
            else
                return abs(d[i][j]);
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        ll right=INT_MAX,down=INT_MAX;
        ll temp = (d[i][j]>=0) ? -1*d[i][j] : abs(d[i][j]);
        
        if(j+1 < m)
            right = max(temp,temp + Helper(i,j+1,d,n,m,dp));
        if(i+1 < n)
            down = max(temp,temp + Helper(i+1,j,d,n,m,dp));
        
        dp[i][j] = min(right,down);
        return min(right,down);
    }
    
    int calculateMinimumHP(vector<vector<int>>& d) {
        int n = d.size();
        int m = d[0].size();
        int** dp = new int*[n];
        for(int i=0;i<n;i++)
            dp[i] = new int[m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                dp[i][j]=-1;
        }
        ll ans = Helper(0,0,d,n,m,dp);
        if(ans>=0)
            return ans+1;
        else
            return 1;
    }
};