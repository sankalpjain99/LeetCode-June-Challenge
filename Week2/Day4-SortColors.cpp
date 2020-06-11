class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int n = nums.size();
        int j = n-1;
        int x=0;
        while(x<=j){
            if(nums[x]==0)
                swap(nums[x++],nums[i++]);
            else if(nums[x]==2)
                swap(nums[x],nums[j--]);
            else
                x++;
        }
    }
};