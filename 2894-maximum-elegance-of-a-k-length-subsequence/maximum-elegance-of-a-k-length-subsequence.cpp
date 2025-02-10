#define ll long long
#define pi pair<ll,ll>
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        map<ll,ll>mp;
        
        sort(items.begin(),items.end(),greater<vector<int>>());
        ll ans=0;
        int count=0;
        int i=0;
        priority_queue<pi>pq;
        while(count<k){
            mp[items[i][1]]++;
            ans+=1ll*items[i][0];
            pq.push({-items[i][0],i});
            i++;
            count++;
        }
        ll res=ans;
        res+=1ll*mp.size()*1ll*mp.size();
    
        while(i<items.size() && !pq.empty()){
            if(mp[items[i][1]]>0){
                i++;
                continue;
            }

            int curr=pq.top().second;
            pq.pop();
            if(mp[items[curr][1]]==1){
                continue;
            }

            ans+=items[i][0]-items[curr][0];
            mp[items[curr][1]]--;
            mp[items[i][1]]++;
            res=max(1ll*res,1ll*ans+(long long)mp.size()*(long long)mp.size());
        }
        return  res;
    }
};