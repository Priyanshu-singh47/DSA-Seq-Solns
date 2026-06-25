class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;

        for(char c : s)
            mp[c]++;

        vector<string> bucket(s.size() + 1);

        for(auto it : mp) {
            bucket[it.second].append(it.second, it.first);
        }

        string ans = "";

        for(int i = s.size(); i >= 1; i--) {
            ans += bucket[i];
        }

        return ans;
    }
};