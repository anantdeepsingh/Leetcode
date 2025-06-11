const int mod=1e9+7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>next_smaller(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                next_smaller[i]=n;
            }
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                next_smaller[i]=n;
            }
            else{
                next_smaller[i]=st.top();
            }
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int prev=i;
            int next=next_smaller[i];
            int small=arr[i];
            while(next!=n){
                ans=(ans%mod+(next-prev)%mod*(arr[prev])%mod)%mod;
                prev=next;
                next=next_smaller[prev];
                small=arr[prev];
            }
            ans=(ans%mod+(next-prev)%mod*(arr[prev])%mod)%mod;
        }
        return ans;
    }
};