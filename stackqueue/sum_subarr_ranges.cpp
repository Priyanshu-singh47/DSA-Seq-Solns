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

    vector<int> findNGE(vector<int>& arr) {
        int n = arr.size();
        vector<int> NGE(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();

            NGE[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return NGE;
    }

    vector<int> findPGEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> PGEE(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();

            PGEE[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return PGEE;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> nse = findNSE(nums);
        vector<int> psee = findPSEE(nums);
        vector<int> nge = findNGE(nums);
        vector<int> pgee = findPGEE(nums);

        long long minSum = 0;
        long long maxSum = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            minSum += left * right * 1LL * nums[i];
        }

        for (int i = 0; i < n; i++) {
            long long left = i - pgee[i];
            long long right = nge[i] - i;
            maxSum += left * right * 1LL * nums[i];
        }

        return maxSum - minSum;
    }
};