class Solution {
public:

    void dfs(string s,vector<string>& ans,unordered_map<string,multiset<string>>& g){
        while(g[s].size()){
            string v = *g[s].begin();
            g[s].erase(g[s].begin());
            dfs(v,ans,g);
        }
        ans.push_back(s);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> g;
        for(auto x:tickets)
            g[x[0]].insert(x[1]);
        vector<string> ans;
        int n = tickets.size();
        dfs("JFK",ans,g);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};