class Solution {
public:
    bool possible(vector<int>v , int midval , int m , int k){
        int count=0;int noofB=0;
        for(int i=0;i<v.size();i++){
            if(midval>=v[i]){
                count++;
            }
            else{
                noofB+=count/k;
                count=0;

            }

        }
        noofB+=count/k;
        if(noofB>=m){
            return true;
        }
        else return false ;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();int maxi=INT_MIN;int mini =INT_MAX;
        for(int i=0;i<n;i++){
            maxi=max(maxi,bloomDay[i]);
            mini=min(mini,bloomDay[i]);

        }
        int low=mini;int high=maxi;int ans;
        long long val = m*1LL *k*1LL;
        if(val>n) return -1;
        while(low<=high){
            int mid=(low+high)/2;
            if (possible(bloomDay,mid,m,k)==true){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};