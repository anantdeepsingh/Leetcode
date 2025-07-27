class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int n=arr.size();
       int low=0,high=n-1;

       int ind=-1;
       while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]-mid-1<k){
            ind=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
       }

       int curr=ind>=0?arr[ind]-ind-1:0;
       int left=k-curr;
        if(ind==-1) return left;
       return arr[ind]+left;
    }
};