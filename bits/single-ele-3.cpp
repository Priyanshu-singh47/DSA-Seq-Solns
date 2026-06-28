class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();int rightmost=0;
        long XORR=0;
        for(int i=0 ;i<n ;i++){
            XORR=XORR^nums[i];
           rightmost=(XORR & (XORR-1)) ^ XORR;

        }
        int b1=0; int b2=0;
        for (int i=0; i<n;i++){
            if(nums[i] & rightmost){
                b1=b1^nums[i];
            }
            else b2=b2^nums[i];
        }
        return {b1,b2};
        
    }
};