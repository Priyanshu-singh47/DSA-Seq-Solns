class Solution {
public:
    
    int calfn(vector<int>v,int pgs){
        int cntstd=1;int pgstu=0;
        for(int i=0;i<v.size();i++){
            if((v[i]+pgstu)<=pgs){
                pgstu+=v[i];
            }
            else{
                cntstd++;
                pgstu=v[i];
            }
        }
        return cntstd;
    }
    int findPages(vector<int> &nums, int m)  {
        int n=nums.size();
        if(m>n) return -1;
        int sum=0;int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxi=max(maxi,nums[i]);

        }
        int low=maxi;int high=sum;int val=0;int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            val=calfn(nums,mid);
            if(val<=m){
                ans=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }    
        }
        return ans;
    }

    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,k);
    }  

};