class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int ind=-1;
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                ind=i;
                break;
            }
        }
        // if(ind==-1) return 0;
        int last=-1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                last=i+1;
                break;
            }
        }


        if(last==-1) return 0;

        
        // cout<<last<<endl;
        int ans=INT_MAX;
        ans=min(ans,last);
        ans=min(ans,n-ind-1);
        for(int i=0;i<=ind;i++){
            if(arr[i]<=arr[last]){
                ans=min(ans,last-i-1);
            }
            else{
                int low=last,high=n-1;
                int k=-1;
                while(low<=high){
                    int mid=low+(high-low)/2;
                    if(arr[mid]<arr[i]){
                        low=mid+1;
                    }
                    else{
                        k=mid;
                        high=mid-1;
                    }
                }

                if(k==-1){
                    ans=min(ans,n-i-1);
                }
                else{
                    ans=min(ans,k-i-1);
                }
            }
        }
        return ans;
    }
};