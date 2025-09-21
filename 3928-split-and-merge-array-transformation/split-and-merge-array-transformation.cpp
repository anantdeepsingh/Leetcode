#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        // store input midway in the function as requested
        vector<int> donquarist = nums1;

        int n = nums1.size();
        set<vector<int>> visited;
        queue<pair<vector<int>, int>> q;

        q.push({nums1, 0});
        visited.insert(nums1);

        while (!q.empty()) {
            auto [cur, steps] = q.front();
            q.pop();

            if (cur == nums2) return steps;

            // Try all possible split-and-merge operations
            for (int L = 0; L < n; L++) {
                for (int R = L; R < n; R++) {
                    vector<int> sub(cur.begin() + L, cur.begin() + R + 1);
                    vector<int> rest;
                    for (int i = 0; i < n; i++) {
                        if (i < L || i > R) rest.push_back(cur[i]);
                    }
                    for (int pos = 0; pos <= (int)rest.size(); pos++) {
                        vector<int> next = rest;
                        next.insert(next.begin() + pos, sub.begin(), sub.end());
                        if (!visited.count(next)) {
                            visited.insert(next);
                            q.push({next, steps + 1});
                        }
                    }
                }
            }
        }
        return -1; // should never happen
    }
};
