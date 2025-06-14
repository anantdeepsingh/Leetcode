class Solution {
public:
    int minMaxDifference(int num) {
        string t1=to_string(num);
        string t2=t1;
        char ch1;
        for(int i=0;i<t1.size();i++){
            if(t1[i]=='9') continue;
            else{
                ch1=t1[i];
                break;
            }
        }
        for(int i=0;i<t1.size();i++){
            if(t1[i]==ch1){
                t1[i]='9';
            }
        }
        int maxi=stoi(t1);
        char ch=t2[0];
        for(int i=0;i<t2.size();i++){
            if(t2[i]==ch){
                t2[i]='0';
            }
        }
        int mini=stoi(t2);
        return maxi-mini;
    }
};