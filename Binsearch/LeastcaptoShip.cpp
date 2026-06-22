class Solution {
public:
    int calfn(vector<int> &v,int K){int sumnn=0;int days=1;
        for(int i=0;i<v.size();i++){
           sumnn+=v[i];
           if(sumnn>K){
            days++;
            sumnn=v[i];
           }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();int maxi=INT_MIN; ;int Sum=0;
        for(int i=0;i<n;i++){
            Sum+=weights[i];
            maxi=max(maxi,weights[i]);

        }
        int low=maxi;int high=Sum;int val=0;int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            val=calfn(weights,mid);
            if (val<=days){
                ans=mid;
                high=mid-1;

            }
            else low=mid+1;
        }
        return ans;

        
    }
};