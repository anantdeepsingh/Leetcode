class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        
        for (auto &it : buildings) {
            int left = it[0];
            int right = it[1];
            int height = it[2];

            events.push_back({left, -height});  // Start of building
            events.push_back({right, height});  // End of building
        }

        sort(events.begin(), events.end());

        multiset<int> heights = {0};  // Ground level
        int prev_max = 0;

        vector<vector<int>> ans;

        for (auto &[x, h] : events) {
            if (h < 0) {
                heights.insert(-h);  // Add building height
            } else {
                heights.erase(heights.find(h));  // Remove building height
            }

            int curr_max = *heights.rbegin();
            if (curr_max != prev_max) {
                ans.push_back({x, curr_max});
                prev_max = curr_max;
            }
        }

        return ans;
    }
};
