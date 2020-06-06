class Solution {
public:
    
    static bool comp(pair<int,int> a,pair<int,int> b){
        if(a.first==b.first)
            return a.second<b.second;
        else
            return a.first>b.first;
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if(people.size()==1 || people.size()==0)
            return people;
        vector<pair<int,int>> v;
        for(auto x:people)
            v.push_back(make_pair(x[0],x[1]));
        sort(v.begin(),v.end(),comp);
        vector<vector<int>> ans;
        ans.push_back({v[0].first,v[0].second});
        for(int i=1;i<v.size();i++){
            int j=0;
            while(j<ans.size() && j!=v[i].second)
                j++;
            ans.insert(ans.begin()+j,{v[i].first,v[i].second});
        }
        return ans;
    }
};