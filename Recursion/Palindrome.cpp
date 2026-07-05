class Solution {
public:
    bool funccal(const string &s, int i, int n) {
        if(i >= n/2) return true;

        if(s[i] != s[n-i-1]) return false;

        return funccal(s, i+1, n);
    }

    bool isPalindrome(string s) {

        string clean = "";

        for(char c : s) {
            if(isalnum(c))
                clean += tolower(c);
        }

        return funccal(clean, 0, clean.length());
    }
};