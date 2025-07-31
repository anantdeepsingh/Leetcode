class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        auto b=nums;
        for(int i=0;i<n;i++){
            int ind=(i-k+n)%n;
            nums[i]=b[ind];
        }
    }
};