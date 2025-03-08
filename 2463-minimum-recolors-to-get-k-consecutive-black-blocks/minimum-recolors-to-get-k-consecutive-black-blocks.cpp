class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt=0;
        int n=blocks.size();
        int l=0,r=0;
        int ans=INT_MAX;
        while(r<n){
            if(blocks[r]=='W'){
                cnt++;
            }
            while(r-l+1>k){
                if(blocks[l]=='W'){
                    cnt--;
                }
                l++;
            }

            if(r-l+1==k){
                ans=min(ans,cnt);
            }
            r++;
        }
        return ans;
    }
};