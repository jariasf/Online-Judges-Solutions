/*******************************************
 ***Problem: Maximum Score After Splitting a String    
 ***ID: 1422
 ***Judge: LeetCode
 ***Type: Ad hoc
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int maximum = 0;
        int zeros = 0;
        int ones = 0;
        for( int i = n - 1 ; i >= 0 ; --i )
            ones += (s[i] == '1');
        
        for( int i = 0 ; i < n - 1 ; ++i ){
            if( s[i] == '0') zeros++;
            else if( s[i] == '1') ones--;
            maximum = max(zeros + ones, maximum);            
        }
                
        return maximum;
    }
    
};
