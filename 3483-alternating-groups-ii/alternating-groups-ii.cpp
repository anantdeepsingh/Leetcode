class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        
        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }

        int n=colors.size();

        int red=0,blue=0;
        int l=0,r=1;
        int cnt=0;
        while(r<n){
           
            if(colors[r]==colors[r-1]){
                l=r;
            }

            if(r-l+1>k){
                l++;
            }

            if(r-l+1==k){
                cnt++;
            }
            r++;
        }
        return cnt;
    }
};