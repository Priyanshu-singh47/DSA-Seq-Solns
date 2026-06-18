class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstindx=firstocc(nums,target);
        if(firstindx==-1) return{-1,-1};
        return{firstindx,lastocc(nums,target)};
    }

int firstocc(vector<int>& nums, int target){
    int l=0;int h=nums.size()-1;int first=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(nums[mid]==target){
            first=mid;
            h=mid-1;


        }
        else if(nums[mid]>target) h=mid-1;
        else l=mid+1;
    }
    return first;
}
int lastocc(vector<int>& nums, int target){
    int l=0;int h=nums.size()-1;int last=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(nums[mid]==target){
            last=mid;
            l=mid+1;


        }
        else if(nums[mid]>target) h=mid-1;
        else l=mid+1;
    }
    return last;
}


};