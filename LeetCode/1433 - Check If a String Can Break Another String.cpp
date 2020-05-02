/*******************************************
 ***Problem: Check If a String Can Break Another String
 ***ID: 1433
 ***Judge: LeetCode
 ***Type: Sorting
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool correct(string &s1, string &s2){
        for( int i = 0 ; i < s1.size(); ++i ){
            if( s1[i] < s2[i] ) return false;
        }
        return true;
    }
    
    bool checkIfCanBreak(string s1, string s2) {
        sort( s1.begin(), s1.end());
        sort( s2.begin(), s2.end());
        if( correct(s1, s2) || correct(s2, s1) ) return true;         
        return false;
    }
};
