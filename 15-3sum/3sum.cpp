class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       set<vector<int>>st;
       vector<vector<int>>ans;
       for(int i=0;i<nums.size();i++){
            int curr=nums[i];
            int l=i+1,r=nums.size()-1;
            while(l<r){
                if(nums[l]+nums[r]==(-curr)){
                   st.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                else if(nums[l]+nums[r]>(-curr)){
                    r--;
                }
                else{
                    l++;
                }
            }
       } 
       ans.insert(ans.end(), st.begin(), st.end());
       return ans;
    }
};