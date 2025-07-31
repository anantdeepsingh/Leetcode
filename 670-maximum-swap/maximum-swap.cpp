class Solution {
public:
    int maximumSwap(int num) {
        vector<int>digits;
        int temp=num;
        while(temp>0){
            int rem=temp%10;
            digits.push_back(rem);
            temp=temp/10;
        }

        sort(digits.begin(),digits.end(),greater<int>());
        string s=to_string(num);
        int ind=0;
        for(auto it:s){
            int d=it-'0';
            if(d==digits[ind]){
                ind++;
                continue;
            }
            else{
                break;
            }
        }
        cout<<ind<<endl;

        if(ind==s.size()) return num;
        char ch=digits[ind]+'0';
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==ch){
                swap(s[i],s[ind]);
                break;
            }
        }

        int ans=stoi(s);
        return ans;
    }
};