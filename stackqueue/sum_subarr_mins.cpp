class Solution {
public:
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSE(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            NSE[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return NSE;
    }

    vector<int> findPSEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> PSEE(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            PSEE[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return PSEE;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int mod = 1e9 + 7;

        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;

            total = (total + (left * right % mod) * arr[i] % mod) % mod;
        }

        return (int)total;
    }
};