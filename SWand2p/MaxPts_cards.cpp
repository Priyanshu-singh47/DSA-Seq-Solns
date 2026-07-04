class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();int sum=0;int maxval=0;
        for(int i=0;i<=k-1;i++){
           sum+=cardPoints[i];
           
        }
        maxval=sum;int j=k-1;
        for(int i=n-1;i>=n-k ; i--){
            sum-=cardPoints[j];
            sum+=cardPoints[i];
            maxval=max(maxval,sum);
            j--;

        }
        return maxval;
    }
};