class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>a(2*n);
        for(int i=0;i<2*n;i++){
            a[i]=nums[i%n];
        }
        stack<int>st;
        vector<int>next_greater(a.size());
        for(int i=a.size()-1;i>=0;i--){
            if(st.empty()){
                next_greater[i]=-1;
            }
            while(!st.empty() && a[st.top()]<=a[i]){
                st.pop();
            }
            if(st.empty()){
                next_greater[i]=-1;
            }
            else{
                next_greater[i]=a[st.top()];
            }
            st.push(i);
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=next_greater[i];
        }
        return ans;
    }
};