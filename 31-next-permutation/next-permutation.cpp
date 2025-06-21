class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // using stl 
        //  next_permutation(nums.begin(),nums.end());

        //  using the logic behind stl
        int ind=-1;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                ind=i;
            }
        }
        if(ind==-1) sort(nums.begin(),nums.end());
        else{
             int j=n-1;
        while(ind<j){
            if(nums[j]>nums[ind]){
                swap(nums[j],nums[ind]);
                break;
            }
            j--;
        }
        sort(nums.begin()+ind+1,nums.end());
        }
       

        
        

    }
};