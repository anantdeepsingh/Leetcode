class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        queue<pair<vector<int>,int>>q;
        q.push({nums1,0});
        int n=nums1.size(); 
        set<vector<int>>visit;
        while(!q.empty()){
            auto [curr,steps]=q.front();
            q.pop();
            if(curr==nums2) return steps;
            for(int l=0;l<n;l++){
                for(int r=l;r<n;r++){
                    vector<int>sub;
                    for(int j=l;j<=r;j++){
                        sub.push_back(curr[j]);
                    }
                    vector<int>rest;
                    for(int i=0;i<n;i++){
                        if(i<l || i>r) rest.push_back(curr[i]);
                    }

                    for(int i=0;i<=rest.size();i++){
                        vector<int>next;
                        next=rest;
                        next.insert(next.begin()+i,sub.begin(),sub.end());

                        if(!visit.count(next)){
                            visit.insert(next);
                            q.push({next,steps+1});
                        }

                    }
                }
            }
        }

        return -1;
    }
};