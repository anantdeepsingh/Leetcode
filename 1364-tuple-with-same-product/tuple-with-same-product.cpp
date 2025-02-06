class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
               if(i!=j) v.push_back(nums[i]*nums[j]);
            }
        }

        map<int,int>mp;
        int ans=0;



        for(int i=0;i<v.size();i++){
            if(mp.find(v[i])!=mp.end()){
                cout<<v[i]<<endl;
                ans+=mp[v[i]];
            }

            mp[v[i]]++;
        }


        return ans*8;
    }
};