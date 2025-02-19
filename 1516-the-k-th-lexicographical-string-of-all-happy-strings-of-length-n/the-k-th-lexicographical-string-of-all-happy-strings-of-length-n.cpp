class Solution {
public:
    char a[3]={'a','b','c'};
    priority_queue<string,vector<string>,greater<string>>pq;
    void solve(int ind,int prev,string &s,int n){
        if(ind==n){
            pq.push(s);
            return;
        }
        for(int i=0;i<3;i++){
            if(i!=prev){
                s+=a[i];
                solve(ind+1,i,s,n);
                s.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        string s="";
        solve(0,-1,s,n);
        int cnt=0;
        k--;
        while(!pq.empty() && k>0){
          pq.pop();
          k--;
        }

        if(!pq.empty()) return pq.top();
        return "";
    }
};