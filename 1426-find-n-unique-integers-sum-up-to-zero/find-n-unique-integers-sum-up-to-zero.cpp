class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        int mid=n/2;
        for(int i=mid;i>0;i--){
            ans.push_back(-i);
        }
        if(n%2!=0)ans.push_back(0);
        for(int i=1;i<=mid;i++){
            ans.push_back(i);
        }
        return ans;
    }
};