class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<int> heights(m, 0);  // Histogram heights for each row

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            vector<int> next_smaller(m, m);
            stack<int> st;
            for (int j = m - 1; j >= 0; j--) {
                while (!st.empty() && heights[st.top()] >= heights[j]) {
                    st.pop();
                }
                if (!st.empty()) {
                    next_smaller[j] = st.top();
                }
                st.push(j);
            }
            vector<int> prev_smaller(m, -1);
            while (!st.empty()) st.pop(); // Clear stack
            for (int j = 0; j < m; j++) {
                while (!st.empty() && heights[st.top()] >= heights[j]) {
                    st.pop();
                }
                if (!st.empty()) {
                    prev_smaller[j] = st.top();
                }
                st.push(j);
            }
            for (int j = 0; j < m; j++) {
                int height = heights[j];
                int width = next_smaller[j] - prev_smaller[j] - 1;
                int side = min(height, width);
                ans = max(ans, side * side);
            }
        }

        return ans;
    }
};
