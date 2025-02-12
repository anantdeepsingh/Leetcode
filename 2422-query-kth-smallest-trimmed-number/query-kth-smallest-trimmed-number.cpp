#define pi pair<string,int>
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int m=nums[0].size();
        int n=nums.size();
        vector<int>ans;
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        for(auto it:queries){
            int k=it[0]-1;
            int len=it[1];
            for(int i=0;i<n;i++){
                string temp=nums[i].substr(m-len);
                pq.push({temp,i});
            }
            while(k>0 && !pq.empty()){
                pq.pop();
                k--;
            }

            int ind=pq.top().second;
            ans.push_back(ind);
            while(!pq.empty()){
                pq.pop();
            }
        }

        return ans;
    }
};