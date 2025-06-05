class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        for(int i=0;i<n;i++){
            int target=-nums[i];
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[j]+nums[k];
                if(sum==target){
                    st.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(sum>target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }

        vector<vector<int>>ans;
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};