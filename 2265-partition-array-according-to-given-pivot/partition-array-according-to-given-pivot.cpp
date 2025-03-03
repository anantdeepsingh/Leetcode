class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>a1;
        vector<int>a2;
        vector<int>a3;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                a1.push_back(nums[i]);
            }
            else if(nums[i]==pivot){
                a2.push_back(nums[i]);
            }
            if(nums[i]>pivot){
                a3.push_back(nums[i]);
            }
        }

        int i=0;
        while(i<a1.size()){
            ans.push_back(a1[i]);
            i++;
        }
        i=0;
        while(i<a2.size()){
            ans.push_back(a2[i]);
            i++;
        }
        i=0;
        while(i<a3.size()){
            ans.push_back(a3[i]);
            i++;
        }
        return ans;
    }
};