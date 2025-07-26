class Solution {
public:
    bool isPossible(int currDay,vector<int>& bloomDay, int m, int k){
        int bouquets=0;
        int adj=0;
        for(int i=0;i<bloomDay.size();i++){
            if(currDay>=bloomDay[i]){
                adj++;
            }
            else{
                bouquets+=adj/k;
                adj=0;
            }
        }
        bouquets+=adj/k;

        return bouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mn=*min_element(bloomDay.begin(),bloomDay.end());
        int mx=*max_element(bloomDay.begin(),bloomDay.end());

        int n=bloomDay.size();
        if(1ll*m*k>n) return -1;
        int low=mn,high=mx;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(mid,bloomDay,m,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};

// tc: O(2*n) + O(logn*n)
// sc: O(1)