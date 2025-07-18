#define ll long long
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        ll n=nums.size();
        ll k=(n-n/3)/2;
        vector<ll>left;
        ll score=0ll;
        priority_queue<ll>max_heap;
        for(int i=0;i<n-k;i++){
            score+=1ll*nums[i];
            max_heap.push(1ll*nums[i]);

            if(max_heap.size()>k){
                ll top=max_heap.top();
                max_heap.pop();
                score-=1ll*top;
            }

            if(max_heap.size()==k){
                left.push_back(1ll*score);
            }
        }

        vector<ll>right;
        score=0ll;
        priority_queue<ll,vector<ll>,greater<ll>>min_heap;
        for(ll i=n-1;i>=k;i--){
            score+=1ll*nums[i];
            min_heap.push(1ll*nums[i]);

            if(min_heap.size()>k){
                ll top=min_heap.top();
                min_heap.pop();
                score-=1ll*top;
            }

            if(min_heap.size()==k){
                right.push_back(score);
            }
        }

        // for(auto &it:left){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // for(auto &it:right){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        ll sz=left.size();
        ll l=0,r=sz-1;
        ll ans=LLONG_MAX;
        while(l<sz){
            ans=min(ans,left[l]-right[r]);
            l++;
            r--;
        }

        return ans;
    }
};