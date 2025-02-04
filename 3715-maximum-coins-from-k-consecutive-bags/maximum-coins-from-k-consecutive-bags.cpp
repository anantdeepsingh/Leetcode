class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        //sort the array and store starts and ends of interval seperately to make binary search easier
        int n = coins.size();
        sort(coins.begin(), coins.end()); 
        vector<long long> prefix(coins.size()+1, 0); 
        vector<int> starts(n), ends(n);

        //precalculate the prefix sum for calculation of score
        for(int i=0; i<n; i++){
            starts[i] = coins[i][0]; 
            ends[i] = coins[i][1]; 
            prefix[i+1] = prefix[i] + 1LL*(coins[i][1]-coins[i][0]+1)*coins[i][2];
        }

        long long ans = 0; //final_score

        // First loop: Treat each coin-containing interval as the start of the k-length interval
        for(int i=0; i<n; i++){
            long long curr = 0; //score for this iteration
            int s = coins[i][0], target = s + k - 1; 
            int j = lower_bound(ends.begin(), ends.end(), target)- ends.begin();
            curr += 1LL*(prefix[j] - prefix[i]); 
            if(j<n) curr += 1LL*max(0, target - coins[j][0] + 1)*coins[j][2]; //handle partial overlap
            ans = max(curr, ans); 
        }

        // Second loop: Treat each coin-containing interval as the end of the k-length interval
        for(int i=0; i<n; i++){
            long long curr = 0;
            int s = coins[i][1]; 
            int target = s - k + 1; 
            int j = lower_bound(starts.begin(), starts.end(), target) - starts.begin();
            curr += 1LL*(prefix[i+1] - prefix[j]); 
            if(j>0) curr += 1LL*max(0,  coins[j-1][1] - target + 1)*coins[j-1][2]; //handle partial overlap
            ans = max(curr, ans); 
        }
        
        return ans;
    }
};