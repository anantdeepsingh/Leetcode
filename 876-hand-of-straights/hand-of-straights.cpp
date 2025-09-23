class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        multiset<int> st(hand.begin(), hand.end());

        while (!st.empty()) {
            int start = *st.begin();
            for (int i = 0; i < groupSize; i++) {
                auto it = st.find(start + i);
                if (it == st.end()) return false;
                st.erase(it);
            }
        }
        return true;
    }
};
