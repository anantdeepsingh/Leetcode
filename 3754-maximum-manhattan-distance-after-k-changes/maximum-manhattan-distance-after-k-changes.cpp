class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        int countEast=0,countWest=0,countNorth=0,countSouth=0;
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == 'E'){
                countEast++;
            }
            else if (c == 'W'){
                countWest++;
            }
            else if (c == 'N'){
                countNorth++;
            }
            else if (c == 'S'){
                countSouth++;
            }

            int n1 = (countEast + countNorth) - (countWest + countSouth); // option 1 when k==0 e + n 
            int n2 = n1 + 2 * min(k, countWest+countSouth);

            int n3= (countWest + countNorth) - (countEast + countSouth);
            int n4 = n3 + 2 * min(k, countEast + countSouth);

            int n5 = (countEast + countSouth) - (countWest + countNorth);
            int n6 = n5 + 2 * min(k, countWest + countNorth );

            int n7 = (countWest+ countSouth) - (countEast + countNorth);
            int n8 = n7 + 2 * min(k, countEast + countNorth);

            int best = max({n2, n4, n6, n8});
            best = max(best, 0);
            best = min(best, i + 1);

            ans = max(ans, best);
        }
        return ans;
    }
};