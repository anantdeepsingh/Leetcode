class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(auto it:nums){
            string t=to_string(it);
            if(t.size()%2==0){
                cnt++;
            }
        }
        return cnt;
    }
};