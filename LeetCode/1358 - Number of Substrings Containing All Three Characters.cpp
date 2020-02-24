/*******************************************
 ***Problem: Number of Substrings Containing All Three Characters
 ***ID: 1358
 ***Judge: LeetCode
 ***Type: Sliding Window
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int numberOfSubstrings(string s) { 
        int n = s.size();
        int total = 0;
        int a, b, c; 
        a = b = c = 0;
        for (int i = 0; i < n; ++i) { 
            if (s[i] == 'a') { 
                a = i + 1; 
                total += min(b, c); 
            } 
            else if (s[i] == 'b') { 
                b = i + 1; 
                total += min(a, c); 
            }
            else { 
                c = i + 1; 
                total += min(a, b); 
            } 
        } 

        return total;
    }   
};
