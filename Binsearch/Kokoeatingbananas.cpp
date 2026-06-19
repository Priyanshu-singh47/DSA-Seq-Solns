class Solution {
public:
    int maxval(vector<int>v){
        int maxi=0;
        for(int i=0;i<v.size();i++){
            maxi=max(maxi,v[i]);
        }
        return maxi;
    }

    long long Calhrs(vector<int>v,int K){
        long long hrs=0;
           for(int i=0;i<v.size();i++){
         hrs+=ceil(double(v[i])/double(K));
           }
           return hrs;
    }

    

    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;int high=maxval(piles);
        while(low<=high){
            int mid=(low+high)/2;
            long long ans=Calhrs(piles,mid);
            if(ans<=h){
                int answer=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};

