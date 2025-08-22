class Solution {
public:
    int myAtoi(string s) {
        string number="";
        int n=s.size();
        int i=0;
        while(i<n && s[i]==' '){
            i++;
        }
        if(i==n) return 0;
        int sign=1;
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+'){
            sign=1;
            i++;
        }

        int mini=INT_MIN;
        int maxi=INT_MAX;
        long long res=0;
        while(i<n && isdigit(s[i])){
            int d=s[i]-'0';
            res=res*10+d;
            if(1ll*sign*res>=INT_MAX) return INT_MAX;
            if(1ll*sign*res<=INT_MIN) return INT_MIN;
            i++;
        }
        return (int)res*sign;
    }
};
