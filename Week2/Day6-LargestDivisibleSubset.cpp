class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n = a.size();
        vector<int> ans;
        if(n==0)
            return ans;
        
        sort(a.begin(),a.end());
        vector<int> dp(n+1,1);
        int max=1;        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i]%a[j]==0 && dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                    if(max<dp[i])
                        max=dp[i];
                }
            }
        }
        
        int prev=-1;
        for(int i=n-1;i>=0;i--){
            if(dp[i]==max && (prev%a[i]==0 || prev==-1)){
                ans.push_back(a[i]);
                max--;
                prev = a[i];
            }
        }
        return ans;
    }
};