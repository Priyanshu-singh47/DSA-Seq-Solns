class Solution{
public:
    int lowerBound(vector<int> &nums, int x){
        int l=0;int h=nums.size()-1;int ans=nums.size();
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]>=x){
                ans=mid;
                h=mid-1;

            }
            
            else l=mid+1;
        }

            return ans;      
             
        
    }
};