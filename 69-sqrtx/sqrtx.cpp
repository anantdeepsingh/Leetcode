class Solution {
public:
    int mySqrt(int x) {
        int low=0,high=1e5;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(1ll*mid*mid<=x){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return high;
    }
};