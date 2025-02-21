class Solution {
public:

    int dp[11][2][2][11][11][21];
    int solve(int ind,bool is_smaller,bool is_started,int cnt1,int cnt2,int rem,string &s,int k){

        if(ind==s.size()){
            if(is_started && cnt1==cnt2 && rem==0) return 1;
            return 0;
        }

        if(dp[ind][is_smaller][is_started][cnt1][cnt2][rem]!=-1) return dp[ind][is_smaller][is_started][cnt1][cnt2][rem];
        int high=is_smaller?9:s[ind]-'0';
        int ans=0;
        for(int i=0;i<=high;i++){
            bool new_is_started=is_started || i!=0;
            bool new_smaller=is_smaller || i!=high;
            int new_odd=0,new_even=0;
            if(new_is_started){
                new_odd=cnt1+((i%2)==1);
                new_even=cnt2+((i%2)==0);
            }
            int new_rem=rem*10+i;
            new_rem=new_rem%k;
            ans+=solve(ind+1,new_smaller,new_is_started,new_odd,new_even,new_rem,s,k);
        }
        return dp[ind][is_smaller][is_started][cnt1][cnt2][rem]=ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string s1=to_string(high);
        string s2=to_string(low-1);
        memset(dp,-1,sizeof(dp));
        int h=solve(0,0,0,0,0,0,s1,k);
        memset(dp,-1,sizeof(dp));
        int l=solve(0,0,0,0,0,0,s2,k);
        return h-l;
    }
};