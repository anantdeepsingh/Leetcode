class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a=nums[0];
        int b=nums[1];
        int c=nums[2];
        map<int,int>mp;
        mp[a]++;
        mp[b]++;
        mp[c]++;

        if(a+b<=c || b+c<=a || c+a<=b){
            return "none";
        }

        if(mp.size()==1){
            return "equilateral";
        }
        else if(mp.size()==2){
            return "isosceles";
        }

        return "scalene";
    }
};