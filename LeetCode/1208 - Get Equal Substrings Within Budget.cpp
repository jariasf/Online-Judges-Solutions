/*******************************************
 ***Problema: Get Equal Substrings Within Budget
 ***ID: 1208
 ***Juez: LeetCode
 ***Tipo: Window Sum
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int res = 0;
        int n = s.size();
        vector<int> dif(n);
        for( int i = 0 ; i < n ; ++i ){
            dif[i] = abs(t[i] - s[i]);
        }
        int sum = 0, left = 0;
        for( int i = 0 ; i < n ; ++i ){   
            sum += dif[i];
            while( left <= i && sum > maxCost ){
                sum -= dif[left];
                left++;
            }
            if( left <= i )
                res = max(res, i - left + 1);
        }
        return res;      
    }
};
