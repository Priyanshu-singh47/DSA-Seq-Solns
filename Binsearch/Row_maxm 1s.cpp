class Solution {
public:
    int lowerBound(vector<int>& arr, int x) {
        int low = 0, high = arr.size() - 1;
        int ans = arr.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    int rowWithMax1s(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        int maxOnes = 0;
        int ans = -1;

        for (int i = 0; i < n; i++) {
            int idx = lowerBound(mat[i], 1);
            int ones = m - idx;

            if (ones > maxOnes) {
                maxOnes = ones;
                ans = i;
            }
        }

        return ans;
    }
};