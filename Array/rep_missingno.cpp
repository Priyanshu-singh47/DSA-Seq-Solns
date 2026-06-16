class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {

        long long n = nums.size();

        long long SN = (n * (n + 1)) / 2;
        long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

        long long S = 0;
        long long S2 = 0;

        for (int i = 0; i < n; i++) {
            S += nums[i];
            S2 += 1LL * nums[i] * nums[i];
        }

        long long val1 = S - SN;          // X - Y
        long long val2 = S2 - S2N;        // X² - Y²

        val2 = val2 / val1;               // X + Y

        long long X = (val1 + val2) / 2;  // repeating
        long long Y = X - val1;           // missing

        return {(int)X, (int)Y};
    }
};