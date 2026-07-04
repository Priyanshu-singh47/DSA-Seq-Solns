class Solution {
public:
    int noofsubarr(vector<int>nums,int k){
        int n=nums.size();int sum=0;
        int l=0;int r=0; int cnt=0;
        if(k<0) return 0;
        while(r<n){
            sum+=nums[r]%2;
            while(sum>k){
                sum-=nums[l]%2;
                l++;
            }
            cnt+=r-l+1;
            r++;

 
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return noofsubarr(nums,k)-noofsubarr(nums,k-1);
    }
};