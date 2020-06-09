class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        int n1 = s.size();
        int n2 = t.size();
        while(j<n2){
            if(t[j]==s[i])
                i++;
            j++;
        }
        if(i==n1)s
            return true;
        else 
            return false;
    }
};