#define ll long long
class Solution {
public:
    long long coloredCells(int n) {
        
       ll ans=1ll*n*n+1ll*(n-1)*(n-1);
       return ans;
    }
};