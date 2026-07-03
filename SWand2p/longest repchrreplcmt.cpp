class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int l=0; int r=0; int maxlen=0; int maxf=0;int hash[26]={0};int change=0;
        while(r<n){
            hash[s[r]-'A']++;
            maxf=max(maxf,hash[s[r]-'A']);
            change=(r-l+1)-maxf;

            if(change>k){
                hash[s[l]-'A']--;
              
                l++;

            }
            if(change<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
        
    }
};