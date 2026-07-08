class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        if(index==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=nums.size()-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1,nums.end());
    }
};

//brute

class Solution {
public:
    void solve(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            solve(nums, idx + 1, ans);
            swap(nums[idx], nums[i]); // backtrack
        }
    }

    void nextPermutation(vector<int>& nums) {
        vector<vector<int>> perms;

        solve(nums, 0, perms);

        sort(perms.begin(), perms.end());

        for (int i = 0; i < perms.size(); i++) {
            if (perms[i] == nums) {
                nums = perms[(i + 1) % perms.size()];
                return;
            }
        }
    }
};