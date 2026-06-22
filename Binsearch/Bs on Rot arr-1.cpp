class Solution {
public:
    int search(vector<int>& nums, int target) {
        int Low=0;int high=nums.size()-1;
        while(Low<=high){
            int mid=(Low+high)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>=nums[Low]){
                if(target>=nums[Low]&&target<=nums[mid]){
                    high=mid-1;
                }
                else Low=mid+1;
            }
            else{
                if(nums[mid]<=target&&target<=nums[high]){
                    Low=mid+1;
                }
                else high=mid-1;
            }
        }
        return -1;
        
    }
};