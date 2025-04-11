class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            int n=s.size();
            if(n%2==0){
                int s1=0;
                for(int i=0;i<n/2;i++){
                    s1+=s[i]-'0';
                }
                int s2=0;
                for(int i=n/2;i<n;i++){
                    s2+=s[i]-'0';
                }
                if(s1==s2){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};