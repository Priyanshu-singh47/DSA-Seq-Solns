class Solution {
public:
    int solve(string &s, int i, long long ans, int sign) {
        // Stop if end of string or current char is not a digit
        if (i >= s.size() || !isdigit(s[i])) {
            ans *= sign;

            if (ans > INT_MAX) return INT_MAX;
            if (ans < INT_MIN) return INT_MIN;

            return (int)ans;
        }

        ans = ans * 10 + (s[i] - '0');

        // Check overflow before the next recursive call
        if (sign == 1 && ans > INT_MAX)
            return INT_MAX;

        if (sign == -1 && -ans < INT_MIN)
            return INT_MIN;

        return solve(s, i + 1, ans, sign);
    }

    int myAtoi(string s) {
        int i = 0;
        int n = s.size();

        // Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        return solve(s, i, 0, sign);
    }
};