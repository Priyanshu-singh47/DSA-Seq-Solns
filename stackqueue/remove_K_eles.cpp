class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>st;
        string res="";
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && st.top()-'0'>num[i]-'0'){
                st.pop();
                k--;
            }
           st.push(num[i]) ;
        }
            while(k>0){ 
                st.pop(); k--;
            }
            if(st.empty()) return "0" ;
            while(!st.empty()){
                res.push_back(st.top());
                st.pop();
            }
            while(res.size()!=0 && res.back()=='0'){
                res.pop_back();
            }
            reverse(res.begin(),res.end());
            if(res.empty()) return "0" ;
            return res;
        //While pushing the st.top() to the res, use res.push_back(st.top()) instead of res = res + st.top() for leetcode, otherwise you'll get a memory limit exceeded error. If I have to guess, it's because string append (+) has a O(string size) where a new string is created and then appended whereas push_back is only O(1)

        
    }
};