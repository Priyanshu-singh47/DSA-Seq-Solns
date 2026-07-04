class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int l=0 ; int r=0; int cnt=0;unordered_map<char,int>mpp;
        while(r<n){
            mpp[s[r]]++;
            
            while(mpp.size()==3){
                cnt+=n-r;
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
            r++;

        }
        return cnt;
    }
};

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen(3, -1);
        int cnt = 0;

        for (int i = 0; i < s.size(); i++) {
            lastSeen[s[i] - 'a'] = i;

            if (lastSeen[0] != -1 &&
                lastSeen[1] != -1 &&
                lastSeen[2] != -1) {

                cnt += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
            }
        }

        return cnt;
    }
};