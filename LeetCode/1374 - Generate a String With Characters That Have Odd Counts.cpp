/*******************************************
 ***Problem: Generate a String With Characters That Have Odd Counts
 ***ID: 1374
 ***Judge: LeetCode
 ***Type: Ad hoc
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string generateTheString(int n) {
        string s = "";
        if( n % 2 == 0 ){
            s += "a";
            n--;
        }
        for( int i = 0; i < n; ++i ) s += "b";
        return s;
    }
};
