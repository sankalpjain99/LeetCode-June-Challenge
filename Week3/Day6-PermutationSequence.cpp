class Solution {
public:
    
    string getPermutation(int n, int k) {
        int fact[10]={1};
        for(int i=1;i<=9;i++)
            fact[i] = fact[i-1]*i;
        string ans="";
        vector<char> alpha{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        
        while(n>0){
            int temp = (k-1) / fact[n-1];
            ans+=alpha[temp];
            alpha.erase(alpha.begin()+temp);
            k = k - temp*fact[n-1];
            n--;
        }
        return ans;
    }
};