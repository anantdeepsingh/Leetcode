#define ll long long
class Solution {
public:
    int minZero(int n){
        int cnt=0;
        while(n>0){
            cnt++;
            n=n/4;
        }

        return cnt;
    }
    long long minOperations(vector<vector<int>>& queries) {
        ll ans=0ll;
        for(auto &it:queries){
            int l=it[0];
            int r=it[1];
            int last=l-1;
            ll cnt=0ll;
            for(int i=1;i<=16;i++){
                int low=l,high=r;
                int ind=-1;
                while(low<=high){
                    int mid=low+(high-low)/2;
                    int op=minZero(mid);
                    if(op<=i){
                        ind=mid;
                        low=mid+1;
                    }
                    else{
                        high=mid-1;
                    }
                }
                if(minZero(ind)==i){
                    cnt+=1ll*(i)*(ind-last);
                    last=ind;
                }
            }


            if(cnt%2==0){
                ans+=1ll*(cnt/2);
            }
            else{
                ans+=1ll*(cnt/2)+1;
            }
        }
        return ans;
    }
};


/*

0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 
0 1 1 1 2 2 2 2 2 2 2  2   2  2 2  2  3  3  3


0=1
1=3
2=12
3=48
4=192
5=798
6=

*/