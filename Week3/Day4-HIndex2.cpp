class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        int i=0,j=n-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(c[mid]==(n-mid))
                return c[mid];
            else if(c[mid]>(n-mid))
                j = mid-1;
            else
                i=mid+1;
        }
        return n-i;
    }
};