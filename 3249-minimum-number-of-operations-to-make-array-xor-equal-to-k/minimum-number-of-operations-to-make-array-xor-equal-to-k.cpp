class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        vector<int>count(30,0);
        int n=nums.size();
        for(int bit=0;bit<30;bit++){
            for(int i=0;i<n;i++){
                if((nums[i]>>bit) & 1){
                    count[bit]++;
                }
            }
        }


        cout<<count[0]<<" "<<count[1]<<endl;
        int res=0;
        for(int i=29;i>=0;i--){
            if(count[i]%2==1){
                int val=1<<i;
                if(val>k){
                    res++;
                }
                else{
                    k=k-val;
                }
            }
            else{
                int val=1<<i;
                if(val<=k){
                    res++;
                    k=k-val;
                }
            }
        }

        return res;
    }
};