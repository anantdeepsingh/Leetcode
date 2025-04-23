class Solution {
public:
    int sumOfDigits(int num){
        int sum=0;
        while(num>0){
            int rem=num%10;
            sum+=rem;
            num=num/10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        vector<int>ans(37,0);
        for(int i=1;i<=n;i++){
            int sum=sumOfDigits(i);
            cout<<sum<<endl;
            ans[sum]++;
        }
        int largest_size=*max_element(ans.begin(),ans.end());
        int cnt=0;
        for(int i=1;i<30;i++){
            if(ans[i]==largest_size){
                cnt++;
            }
        }
        return cnt;
    }
};