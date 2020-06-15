class Solution {
public:
    
    void Helper(int cost,int s,int d,int k,int n,int** g,int& ans){
        if(s==d){
            ans=cost;
            return;
        }
        if(k<0)
            return;
        
        for(int i=0;i<n;i++){
            if(g[s][i]){
                int temp = cost+g[s][i];
                if(temp>ans)
                    continue;
                Helper(temp,i,d,k-1,n,g,ans);
            }
        }
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int K) {
        //MAKE GRAPH
        int** g = new int*[n];
        for(int i=0;i<n;i++)
            g[i] = new int[n]();
        
        for(int i=0;i<f.size();i++){
            g[f[i][0]][f[i][1]] = f[i][2];
        }
        int ans=INT_MAX;
        Helper(0,src,dst,K,n,g,ans);
        if(ans==INT_MAX)
            return -1;
        else
            return ans;
    }
};