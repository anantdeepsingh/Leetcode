class Solution {
public:
    int longestBalanced(string s) {
        // 3 options single character, double character , all 3 characters
        int ans=1,v1=0,v2=0;

        int n=s.size();

        map<pair<int,int>,int>mp;
        mp[{0,0}]=-1;
        // acount=bcount and bcount==c count
        for(int i=0;i<n;i++){
            if(s[i]=='a') v1++;
            else if(s[i]=='c') v2++;
            else{
                v1--;
                v2--;
            }

            if(!mp.count({v1,v2})) mp[{v1,v2}]=i;
            ans=max(ans,i-mp[{v1,v2}]);
        }
        int cnt=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                cnt++;
            }
            else{
                ans=max(ans,cnt);
                cnt=1;
            }
        }
        ans=max(ans,cnt);
        vector<string>combo={"ab","ac","bc"};
        for(auto &it:combo){
            char x=it[0],y=it[1];
            int v=0;
            map<int,int>mp;
            int ind=0;
            mp[0]=-1;
            for(int i=0;i<n;i++){
                if(s[i]==x) v++;
                else if(s[i]==y) v--;
                else{
                    mp.clear();
                    v=0;
                }
                if(!mp.count(v)) mp[v]=i;
                ans=max(ans,i-mp[v]);
            }
        }


        return ans;
    }
};