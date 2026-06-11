class Solution {
public:
    int longestSubarray(vector<int> &nums, int k) {
        map<int , int > prefixmap;
        int sum=0; int maxlen=0;
        for(int i=0; i<nums.size();i++){
            sum+=nums[i];
            if (sum==k){
                maxlen=max(maxlen,i+1);

            }
            int rem=sum-k;
            if(prefixmap.find(rem)!=prefixmap.end()){
                int len=i-prefixmap[rem];
                maxlen=max(maxlen,len);

            }
            if(prefixmap.find(sum)==prefixmap.end()){
                prefixmap[sum]=i;

            }
            
        }
        return maxlen;






    }

};
    