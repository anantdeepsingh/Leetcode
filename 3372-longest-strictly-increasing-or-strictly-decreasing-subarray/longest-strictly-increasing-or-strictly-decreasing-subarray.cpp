class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int last=0;
        int maxi=0;
        while(r<n){

            if(nums[r]<=last){
                l=r;
                last=nums[r];
            }

            maxi=max(maxi,r-l+1);
            last=nums[r];
            r++;
        }



        last=51;

        l=0,r=0;
        while(r<n){


            if(nums[r]>=last){
                l=r;
                last=nums[r];
            }


            maxi=max(maxi,r-l+1);
            last=nums[r];
            r++;
        }

        return maxi;
    }
};