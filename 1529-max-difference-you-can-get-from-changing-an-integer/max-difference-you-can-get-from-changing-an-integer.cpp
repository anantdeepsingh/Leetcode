class Solution {
public:
    int maxDiff(int num) {
        string t1=to_string(num);
        string t2=t1;
        int n1=t1.size();
        int n2=t2.size();
        char ch1;
        for(int i=0;i<n1;i++){
            if(t1[i]=='9') continue;
            else{
                ch1=t1[i];
                break;
            }
        }
        for(int i=0;i<n1;i++){
            if(t1[i]==ch1){
                t1[i]='9';
            }
        }
        int a=stoi(t1);

        map<char,int>mp;
        for(int i=0;i<n2;i++){
            mp[t2[i]]++;
        }
        if((int)mp.size()==1){
            for(int i=0;i<n2;i++){
                t2[i]='1';
            }
        }
        else{
            char ch2;
            int ind=-1;
            if(t2[0]=='1'){
                for(int i=1;i<n2;i++){
                    if(t2[i]=='0' || t2[i]=='1'){
                    continue;
                    }
                    else{
                    ch2=t2[i];
                    break;
                    }
                }
                
                for(int i=0;i<n2;i++){
                    if(t2[i]==ch2){
                        t2[i]='0';
                    }
                }
            }
            else{
                char ch2=t2[0];
                for(int i=0;i<n2;i++){
                    if(t2[i]==ch2){
                        t2[i]='1';
                    }
                }
            }
        }
        int b=stoi(t2);
        return a-b;
    }
};