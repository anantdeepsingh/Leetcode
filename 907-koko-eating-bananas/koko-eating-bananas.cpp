class Solution {
public:
    bool check(int mid,vector<int>&piles,int h){
       
       long long cnt=0ll;

       for(int i=0;i<piles.size();i++){
        cnt+=ceil(piles[i]/(double)mid);
       }

       return cnt<=h;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,piles,h)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};