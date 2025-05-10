#define ll long long
class Solution {
public:
    bool check(ll sum,int cnt,ll mid){
        return mid-sum>=cnt;
    }
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int z1=0,z2=0;
        ll sum1=0ll,sum2=0ll;
        for(auto it:nums1){
            sum1+=it;
            if(it==0){
                z1++;
            }
        }
        for(auto it:nums2){
            sum2+=it;
            if(it==0){
                z2++;
            }
        }

        if(z1==0 && z2==0){
            if(sum1==sum2) return sum1;
            return -1;
        }

       if(z1==0){
        if(sum1<=sum2) return -1;
        ll gap=sum1-sum2;
        if(z2<=gap) return sum1;
        return -1;
       }

       if(z2==0){
        if(sum2<=sum1) return -1;
        ll gap=sum2-sum1;
        if(z1<=gap) return sum2;
        return -1;
       }


        ll low=max(sum1,sum2),high=1e12;
        ll ans=-1;
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(check(sum1,z1,mid) && check(sum2,z2,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }
};