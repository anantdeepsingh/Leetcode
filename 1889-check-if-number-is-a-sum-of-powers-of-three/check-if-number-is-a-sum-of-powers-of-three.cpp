class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 2) return false; // If we get a '2' in base 3, we can't express it using only 1s and 0s
            n /= 3;
        }
        return true;
    }
};
