class Solution {
public:
    
    int Helper(int amt,vector<int>& v,int i,int** dp){
        if(amt==0) return 1;
        if(amt<0 || i>=v.size()) return 0;
        if(dp[amt][i]!=-1) return dp[amt][i];
        int x = Helper(amt-v[i],v,i,dp);
        int y = Helper(amt,v,i+1,dp);
        dp[amt][i] = x+y;
        return x+y;
    }
    
    int change(int amount, vector<int>& coins) {
        int** dp = new int*[amount+1];
        for(int i=0;i<=amount;i++)
            dp[i] = new int[coins.size()+1];
        for(int i=0;i<=amount;i++){
            for(int j=0;j<=coins.size();j++)
                dp[i][j]=-1;
        }
        return Helper(amount,coins,0,dp);
    }
};