class Solution {
public:
    int longestSubarray(vector<int> &nums, int k) {

        int sum = 0;
        int maxlen = 0;
        int j = 0;

        for(int i = 0; i < nums.size(); i++) {

            sum += nums[i];

            while(sum > k) {
                sum -= nums[j];
                j++;
            }

            if(sum == k) {
                maxlen = max(maxlen, i - j + 1);
            }
        }

        return maxlen;
    }
};
    