class Solution {
public:
    vector<int>ans;
    void solve(int i,int n){
        if(i>n) return;
        ans.push_back(i);
        for(int j=0;j<=9;j++){
            int k=i*10+j;
            if(k>n) return;
            solve(k,n);
        }
    }
    vector<int> lexicalOrder(int n) {
        for(int i=1;i<=9;i++){
            solve(i,n);
        }
        return ans;
    }
};