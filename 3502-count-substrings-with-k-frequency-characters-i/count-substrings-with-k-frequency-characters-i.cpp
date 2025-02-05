class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        vector<int> count(26, 0);
        int n = s.size();
        int l = 0, r = 0;
        int cnt = 0;
        int maxFreq = 0; 
        int tcnt=n*(n+1)/2;
        while (r < n) {
            count[s[r] - 'a']++;
            maxFreq = max(maxFreq, count[s[r] - 'a']); // Update max frequency

            while (maxFreq >= k) {
                count[s[l] - 'a']--;
                if (count[s[l] - 'a'] + 1 == maxFreq) {
                    maxFreq = *max_element(count.begin(), count.end()); // Recompute only when needed
                }
                l++;
            }

            cnt += (r - l + 1); 
            r++;
        }

        return tcnt-cnt;
    }
};
