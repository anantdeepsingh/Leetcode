#define ll long long
class Solution {
public:
    ll cnt(vector<int>&nums1,vector<int>&nums2,ll k,ll pro){
        long long productsCount = 0;

        int n = nums2.size();

        for(int i = 0; i < nums1.size(); i++) {
            if(nums1[i] >= 0) {
                int l = 0;
                int r = n-1;
                int m = -1; 
                while(l <= r) {
                    int mid = l + (r-l)/2;
                    long long product = 1LL * nums1[i] * nums2[mid];
                    if(product <= pro) {
                        m = mid;
                        l = mid+1;
                    } else {
                        r = mid-1;
                    }
                }
                productsCount += (m+1); 
            } else {
                int l = 0;
                int r = n-1;
                int m = n; 
                while(l <= r) {
                    int mid = l + (r-l)/2;
                    long long product = 1LL * nums1[i] * nums2[mid];

                    if(product <= pro) {
                        m = mid;
                        r = mid-1;
                    } else {
                        l = mid+1;
                    }
                }
                                                    
                productsCount += (n - m);
            }
        }
        return productsCount;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        ll low=-1ll*1e10,high=1ll*1e10;
        ll ans=0ll;
        while(low<=high){
            ll mid=low+(high-low)/2;
            cout<<mid<<endl;
            cout<<cnt(nums1,nums2,k,mid)<<endl;
            if(cnt(nums1,nums2,k,mid)>=k){
                ans=mid;
                high=mid-1;
            }
            else if(cnt(nums1,nums2,k,mid)<k){
                low=mid+1;
            }
        }
        return ans;
    }
};