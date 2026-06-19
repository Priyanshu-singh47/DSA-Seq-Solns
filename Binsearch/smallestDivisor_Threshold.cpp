class Solution {
public:
    int calfunc(vector<int>v,int K){
        int sum=0;
        for(int i=0;i<v.size();i++){
            sum+=ceil(double(v[i])/K);

        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        int low=1;int ans=0;
        int high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            int val=calfunc(nums,mid);
            if (val<=threshold){
                ans=mid;
                high=mid-1;

              
            }
            else low=mid+1;
        }
        return ans;
        
    }
};

