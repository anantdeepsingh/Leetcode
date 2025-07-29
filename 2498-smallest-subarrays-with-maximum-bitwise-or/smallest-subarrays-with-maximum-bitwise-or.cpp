class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<vector<int>>vis(31);
        for(int j=0;j<31;j++){
            for(int i=0;i<nums.size();i++){
                int bit=(nums[i]>>j)&1;
                if(bit==1){
                    vis[j].push_back(i);
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int maxInd=i;
            for(int j=0;j<31;j++){
                if(vis[j].size()==0) continue;
                auto it=lower_bound(vis[j].begin(),vis[j].end(),i);
                if(it!=vis[j].end()){
                    maxInd=max(maxInd,*it);
                }
            }
            ans.push_back(maxInd-i+1);
        }
        return ans;
    }
};