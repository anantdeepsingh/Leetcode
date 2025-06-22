class Solution {
    vector<bool> isPrime;
    const int MAXN = 100000;
public:
    Solution() : isPrime(100000, true) {
        sieve();
    }
    void sieve() {
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= MAXN; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= MAXN; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }
    int primeSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0;
        multiset<int>st;
        int prev=-1,curr=-1;
        int ans=0;
        while(r<n){
            if(isPrime[nums[r]]){
                prev=curr;
                curr=r;
                st.insert(nums[r]);
            }

            while(st.size() && *st.rbegin()-*st.begin()>k){
                if(isPrime[nums[l]]){
                    st.erase(st.find(nums[l]));
                }

                l++;
            }

            if(st.size()>=2){
                ans+=prev-l+1;
            }
            r++;
        }
        return ans;
    }
};