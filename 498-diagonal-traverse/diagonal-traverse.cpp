class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<pair<int,int>>order;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<m;i++){
            order.push_back({0,i});
        }
        for(int i=1;i<n;i++){
            order.push_back({i,m-1});
        }
        vector<int>ans;
        for(int i=0;i<order.size();i++){
            int x=order[i].first;
            int y=order[i].second;
            vector<int>v;
            while(x<n && y>=0){
                v.push_back(mat[x][y]);
                x++;
                y--;
            }
            
            if(i%2==0){
                reverse(v.begin(),v.end());
            }

            ans.insert(ans.end(), v.begin(), v.end());
        }

        return ans;
    }
};