class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int size = queries.size();
        int count = 0;
        vector<int> colors(n, 0);
        vector<int> ans;

        for (auto& it : queries) {
            int ind = it[0];
            int col = it[1];

            if (colors[ind] != 0) {
                if (ind - 1 >= 0 && colors[ind - 1] == colors[ind]) count--;
                if (ind + 1 < n && colors[ind + 1] == colors[ind]) count--;
            }

            colors[ind] = col;

            if (ind - 1 >= 0 && colors[ind - 1] == col) count++;
            if (ind + 1 < n && colors[ind + 1] == col) count++;

            ans.push_back(count);
        }
        return ans;
    }
};
