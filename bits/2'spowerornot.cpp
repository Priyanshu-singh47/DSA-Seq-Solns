class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n > 0 && (n & (n - 1)) == 0)
            return true;
        return false;
    }
};


class Solution {
public:
    int minBitFlips(int start, int goal) {

        int ans = start ^ goal;
        int cnt = 0;

        while (ans) {
            cnt++;
            ans = ans & (ans - 1);
        }

        return cnt;
    }
};