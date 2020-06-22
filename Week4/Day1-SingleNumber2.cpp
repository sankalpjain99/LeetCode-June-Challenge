class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bits[32]={0};   
        
        //Count Numbers with ith bit as 1
        for(int i=0;i<32;i++){
            for(int x:nums){
                bits[i]+= x>>i & 1;
                bits[i]%=3;
            }
        }
        
        //bits[] contains ans in binary form
        //Convert to Decimal
        int ans=0;
        for(int i=0;i<32;i++){
            ans |= (bits[i]<<i);
        }
        return ans;
    }
};