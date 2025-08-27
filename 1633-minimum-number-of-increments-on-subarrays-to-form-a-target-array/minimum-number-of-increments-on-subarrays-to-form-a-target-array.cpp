class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int operations = 0;
        int prevHeight = 0;

        for (int& height : target) {
            if (height > prevHeight) {
                operations += (height - prevHeight);
            }
            prevHeight = height;
        } 
        return operations;
    }
};