class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int>st;
       for(auto it:nums){
            st.insert(it);
       }
        int maxLen=0;
       for(auto it:st){
        if(st.find(it-1)==st.end()){
            int k=it;
            int len=1;
            while(st.find(k+1)!=st.end()){
                len++;
                k++;
            }
            maxLen=max(maxLen,len);
        }
       }
       return maxLen;
    }
};