class Solution {
public:

    int merge(vector<vector<int>>& intervals) {
       int n=intervals.size();
       vector<vector<int>>ans;
       sort(intervals.begin(),intervals.end());
       ans.push_back(intervals[0]);
       for(int i=1;i<n;i++){
        if(intervals[i][0]<ans.back()[1]){
            ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        }
        else{
            ans.push_back(intervals[i]);
        }
       }
       return ans.size();
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>v;
        vector<vector<int>>m;
        for(auto it:rectangles){
            int a=it[0];
            int b=it[1];
            int c=it[2];
            int d=it[3];
            vector<int>res;
            res.push_back(a);
            res.push_back(c);
            v.push_back(res);
            vector<int>ans;
            ans.push_back(b);
            ans.push_back(d);
            m.push_back(ans);
        }



        
        int cnt1=merge(v);
        int cnt2=merge(m);
        if(cnt1>=3 || cnt2>=3) return true;
        return false;
    }
};