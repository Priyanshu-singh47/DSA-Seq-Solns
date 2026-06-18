class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
   int floor=findfloor(nums,x);
   int ceil=findceil(nums,x);
   return{floor,ceil};
    }
   
    int findceil(vector<int>nums,int x){
        int l=0;int h=nums.size()-1;int ans=nums.size();int a;int b;
    while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]>=x){
                ans=nums[mid];
                h=mid-1; }
            
            else l=mid+1;
        }

            return ans;      
             
   } 
   int findfloor(vector<int>nums,int x){
    int l=0;int h=nums.size()-1;int ans=nums.size();int a;int b;
    while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]<=x){
                ans=nums[mid];
                l=mid+1; }
            
            else h=mid-1;
        }

            return ans;      
             
      } 
     

   //can also write 2 while loops on sequence for them
    
};