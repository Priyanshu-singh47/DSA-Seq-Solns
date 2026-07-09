class Solution {
public:

    void solve(int n, string s, bool prevOne, vector<string> &ans) {

        if (n == 0) {
            ans.push_back(s);
            return;
        }

        solve(n - 1, s + '0', false, ans);

        if (!prevOne) {
            solve(n - 1, s + '1', true, ans);
        }
    }

    vector<string> generateBinaryStrings(int n) {

        vector<string> ans;

        solve(n, "", false, ans);

        return ans;
    }
};