#define ll long long
class Solution {
public:
    int n;
    int dp[1002][1002];
    int solve(int ind,int prev,vector<int>&arr,map<int,int>&mp){
        if(ind==n) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int op1=solve(ind+1,prev,arr,mp);
        int op2=0;
        if(prev==-1){
            op2=solve(ind+1,ind,arr,mp);
        }
        else{
            int val=arr[ind]+arr[prev];
            if(mp.count(val)){
                op2=1+solve(mp[val],ind,arr,mp);
            }
            else{
                op2=solve(ind+1,prev,arr,mp);
            }
        }
        return dp[ind][prev+1]=max(op1,op2);
    }
    int lenLongestFibSubseq(vector<int>& arr) {
       map<int,int>mp;
       n=arr.size();
       for(int i=0;i<n;i++){
            mp[arr[i]]=i;
       }
       int maxi=0;
       for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int prevLast=arr[i];
            int last=arr[j];
            int len=2;
            while(mp.count(prevLast+last)){
                len++;
                maxi=max(maxi,len);
                int val=prevLast+last;
                prevLast=last;
                last = val;
            }
        }
       }
       return maxi;
    }
};