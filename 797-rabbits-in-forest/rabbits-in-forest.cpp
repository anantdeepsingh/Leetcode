class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int>mp;
        int rabbits=0;
        for(auto it:answers){
            if(it==0){
                rabbits++;
                continue;
            }
            mp[it]++;
        }

        for(auto it:mp){
            int div=it.second/(it.first+1);
            int rem=it.second%(it.first+1);
            if(rem!=0){
                div++;
            }
            rabbits+=div*(it.first+1);
        }
        return rabbits;
    }
};