class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        cout<<n<<endl;
        if(n==1) return 1;
        if(n==2) return 2;
        vector<int>v1(100000,0),v2(100000,0);
        map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val=nums[i]^nums[j];
                v1[val]=1;
            }
        }  
        for(int i=0;i<=2048;i++){
            for(int j=0;j<n;j++){
                int val=nums[j]^i;
                if(v1[val]){
                    v2[i]=1;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<=2048;i++){
            if(v2[i]==1){
                cnt++;
            }
        }

        return cnt;
    }
};
