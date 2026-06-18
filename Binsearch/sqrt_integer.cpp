class Solution {
public:
    int floorSqrt(int n) {
        int low = 1;
        int high = n;
        int ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (mid * mid <= n) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};