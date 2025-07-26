class Solution {
public:
    bool isPossible(int cap,vector<int>& weights, int days){
        int sum=0;
        int cnt=1;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(sum<=cap){
                continue;
            }
            else{
                cnt++;
                sum=weights[i];
            }
        }

        return cnt<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=accumulate(weights.begin(),weights.end(),0);
        int mx=*max_element(weights.begin(),weights.end());
        int low=mx,high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(mid,weights,days)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};

// like the question says i need ot transfer all the weights right for sure minimum would be maximum weight i need to transefer anmd maximum would be sum of all wright as days can be 1