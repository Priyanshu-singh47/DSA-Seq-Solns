class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;
        if(n==0) return {};int val=0;
        if(n==1) return {asteroids[0]};
        for(int i=0 ; i<n ; i++){
            if(asteroids[i]>=0){
                st.push(asteroids[i]);
            }
            if(asteroids[i]<0){
                while(!st.empty() &&st.top()>0 && abs(asteroids[i])>st.top()){
                 st.pop();
             
                }
                if(!st.empty() && abs(asteroids[i])==st.top()) {
                    st.pop();
                }
                else if( st.empty() || st.top()<0) st.push(asteroids[i]);
            }
            
        }
       vector<int> ans(st.size());

for (int i = st.size() - 1; i >= 0; i--) {
    ans[i] = st.top();
    st.pop();
}

return ans;
        
    }
};