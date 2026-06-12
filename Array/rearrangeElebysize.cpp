class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans(nums.size());
        int posi=0;int negi=1;
        for(int i=0;i<nums.size();i++){
            if (nums[i]>0){
                ans[posi]=nums[i];
                posi+=2;
            
            }
            else {
            ans[negi]=nums[i];
            negi+=2;
            }
        }
        return ans;
    }
};