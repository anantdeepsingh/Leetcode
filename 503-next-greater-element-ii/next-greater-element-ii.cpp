class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n=a.size();
       
        stack<int>st;
        vector<int>next_greater(n);
        for(int i=2*n-1;i>=0;i--){
            if(st.empty()){
                next_greater[i%n]=-1;
            }
            while(!st.empty() && a[st.top()%n]<=a[i%n]){
                st.pop();
            }
            if(st.empty()){
                next_greater[i%n]=-1;
            }
            else{
                next_greater[i%n]=a[st.top()%n];
            }
            st.push(i%n);
        }
        
        return next_greater;
    }
};