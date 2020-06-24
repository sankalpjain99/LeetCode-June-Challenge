class Solution {
public:
    
    unsigned long long int bino(int x,int y){
        unsigned long long int ans=1;
        if(y > x-y)
            y = x-y;
        for(int i=0;i<y;i++){
            ans *= (x-i);
            ans /= (i+1);
        }
        return ans;
    }
    
    unsigned long long int numTrees(int n) {
        unsigned long long int c = bino(2*n,n);
        return c/(n+1);
    }
};