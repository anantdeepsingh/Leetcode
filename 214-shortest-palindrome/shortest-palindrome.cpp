class Solution {
public:
    string reverse(string t){
        int n=t.size();
        int i=0,j=n-1;
        while(i<j){
            swap(t[i],t[j]);
            i++;
            j--;
        }
        return t;
    }
    string shortestPalindrome(string s) {
        
        string t=reverse(s);

        string match=s+"#"+t;

        int n=match.size();
        vector<int>lps(n,0);
        int j=0,i=1;
        while(i<n){
            if(match[i]==match[j]){
                lps[i]=j+1;
                i++;
                j++;
            }
            else{
                while(j>0 && match[i]!=match[j]){
                    j=lps[j-1];
                }
                if(match[i]==match[j]){
                    lps[i]=j+1;
                    j++;
                }
                i++;
            }
        }

        int cnt=lps[n-1];

        return t.substr(0,t.size()-cnt)+s;
    }
};

// how many suffix in t matches prefix in s