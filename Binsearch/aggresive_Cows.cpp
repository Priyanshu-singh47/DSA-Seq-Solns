class Solution {
public:
    bool canweplace(vector<int>v,int midval,int k){
        int last=v[0];int cntcows=1;
        for(int i=1;i<v.size();i++){
            if((v[i]-last)>=midval){
              cntcows++;
              last=v[i];
            }
            if(cntcows>=k) return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=1;int high=nums[n-1]-nums[0];int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(canweplace(nums,mid,k)==true){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return high;
    }
};