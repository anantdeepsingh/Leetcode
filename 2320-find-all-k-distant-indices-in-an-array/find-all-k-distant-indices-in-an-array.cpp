class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int>st;
        vector<int>index;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==key){
                index.push_back(i);
            }
        }

        for(auto it:index){
            for(int i=0;i<n;i++){
                if(abs(i-it)<=k){
                    st.insert(i);
                }
            }
        }
        vector<int>res;
        for(auto it:st){
            res.push_back(it);
        }
        return res;
    }
};