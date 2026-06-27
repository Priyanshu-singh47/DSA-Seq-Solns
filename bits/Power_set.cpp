class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        int sub=1<<n;
        for(int m=0;m<sub;m++){
            vector<int>subs;
            for(int i=0;i<n;i++){
                if(m&(1<<i)){
                    subs.push_back(nums[i]);
                }
            }
            ans.push_back(subs);
        }
        return ans;

        
    }
};