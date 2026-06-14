class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0;int cnt2=0;
        int n=nums.size();
        int ele1=INT_MIN;int ele2=INT_MIN;
        for(int i=0;i<n;i++){
            if(cnt1==0 && ele2!=nums[i]){
                cnt1=1;
                ele1=nums[i];
            }
            else if(cnt2==0 && ele1!=nums[i]){
                cnt2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele1) cnt1++;
            else if(nums[i]==ele2) cnt2++;

            else{
                cnt1--;cnt2--;
            }
        }
        vector<int>ls;
        int cnt11=0;int cnt22=0;
        for(int i=0;i<n;i++){
            if(ele1==nums[i]) cnt11++;
            if(ele2==nums[i]) cnt22++;
        }
        int mini=(int)(n/3) +1;
        if(cnt11>=mini) ls.push_back(ele1);
        if(cnt22>=mini) ls.push_back(ele2);
        return ls;

        
    }
};