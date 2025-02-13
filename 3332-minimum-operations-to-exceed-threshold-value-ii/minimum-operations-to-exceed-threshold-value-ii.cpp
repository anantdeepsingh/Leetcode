#define ll long long
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        for(auto it:nums){
            pq.push(1ll*it);
        }
        ll cnt=0;
        while(!pq.empty() && pq.top()<k){
            ll x=pq.top();
            pq.pop();
            ll y=pq.top();
            pq.pop();
            ll val=2*x+y;
            pq.push(val);
            cnt++;
        }

        return cnt;
    }
};