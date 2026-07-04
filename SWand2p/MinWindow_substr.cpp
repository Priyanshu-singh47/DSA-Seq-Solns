class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length(); int m=t.length();int cnt=0;
        unordered_map<char,int>mpp;int r=0; int l=0;int sIndex=-1;
       int  minlen=INT_MAX;
        for(int i=0;i<m;i++){
            mpp[t[i]]++;
        }
        while(r<n){
            if(mpp[s[r]]>0) {cnt++;}
             mpp[s[r]]--;
            while(cnt==m){
                if((r-l+1)<minlen){
                    minlen=r-l+1;
                    sIndex=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0){
                    cnt--;
                    
                }
                 l++;
            }
            r++;


        }
        return sIndex==-1? "" : s.substr(sIndex,minlen);
        
    }
};