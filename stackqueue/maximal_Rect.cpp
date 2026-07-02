class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxarea = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int element = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxarea = max(maxarea,
                              heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            int element = st.top();
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            maxarea = max(maxarea,
                          heights[element] * (nse - pse - 1));
        }

        return maxarea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        if(matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> psum(n, vector<int>(m, 0));

        for(int j = 0; j < m; j++) {
            int sum = 0;

            for(int i = 0; i < n; i++) {
                if(matrix[i][j] == '1')
                    sum++;
                else
                    sum = 0;

                psum[i][j] = sum;
            }
        }

        int maxarea = 0;

        for(int i = 0; i < n; i++) {
            maxarea = max(maxarea, largestRectangleArea(psum[i]));
        }

        return maxarea;
    }
};