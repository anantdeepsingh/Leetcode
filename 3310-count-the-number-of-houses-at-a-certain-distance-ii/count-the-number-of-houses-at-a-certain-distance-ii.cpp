typedef long long int ll;

class Solution {
public:
    vector<long long> countOfPairs(int n, int x, int y) {
        vector<ll> prefix(n+2, 0);
        
        if (x > y) swap(x, y);
        
        if (x == y || x+1 == y) {
            for (int i = 1; i <= n; i ++) 
                prefix[1] ++, prefix[n-i+1] --;
        }
        else {
            for (int i = y; i <= n; i ++) 
                prefix[1] ++, prefix[n-i+1] --;

            int m = y - (y-x)/2;
            
            for (int i = m; i < y; i ++)
                prefix[1] ++, prefix[n-i+1] --;

            for (int i = x, to = m; i < m; i ++, to ++) {
                // i ... to
                prefix[1] ++, prefix[to-i+1] --;
                
                if (to+1 <= y) {
                    // to+1 ... y
                    prefix[(i-x) + 1] ++, prefix[(i-x) + (y-to+1)] --;
                }
                
                if (to+1 <= n) {
                    // y+1 ... n
                    prefix[(i-x+1) + 1] ++, prefix[(i-x+1) + n-y+1] --;
                }
            }

            for (int i = 1; i < x; i ++) {
                // i ... m
                prefix[1] ++, prefix[m-i+1] --;

                if (m+1 <= y-1) {
                    // m+1 ... y-1
                    prefix[(x-i+1) + 1] ++, prefix[(x-i+1) + (y-m)] --;
                }
            
                // y ... n
                prefix[(x-i) + 1] ++, prefix[(x-i) + (n-y+2)] --;
            }
        }
        
        vector<ll> result(n, 0);
        for (int j = 1; j <= n; j++) {
            prefix[j] += prefix[j-1];
            result[j-1] = prefix[j]*2;
        }
        
        return result;
    }
};