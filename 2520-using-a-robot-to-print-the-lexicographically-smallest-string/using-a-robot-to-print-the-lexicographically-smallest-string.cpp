class Solution {
public:
    string robotWithString(string s) {
        set<pair<char, int>> order;  // keeps (char, index) in lexicographic order
        stack<char> st;
        int n = s.size();

        // Insert all characters with their indices into the set
        for (int i = 0; i < n; i++) {
            order.insert({s[i], i});
        }

        string ans = "";
        for (int i = 0; i < n; i++) {
            order.erase({s[i], i});  // remove current char from set

            st.push(s[i]);  // push current char to stack

            // While top of stack is <= the smallest remaining character
            while (!st.empty() && (order.empty() || st.top() <= order.begin()->first)) {
                ans += st.top();
                st.pop();
            }
        }

        // Empty the remaining stack
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};
