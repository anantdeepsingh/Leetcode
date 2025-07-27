class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int>removed(n,0);
        removed[n-1]=0;
        vector<int>ans(n,0);
        ans[n-1]=0;
        stack<int>st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            
            while(!st.empty() && heights[i]>heights[st.top()]){
                removed[i]++;
                st.pop();
            }
            if(!st.empty()){
                removed[i]++;
            }
            ans[i]+=removed[i];
            st.push(i); 
        }

        return ans;
    }
};