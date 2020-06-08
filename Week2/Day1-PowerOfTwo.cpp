class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        double x = (double) log2(n);
        int y = log2(n);
        double z = x-y;
        if(x-y==0.0)
            return true;
        else
            return false;
    }
};