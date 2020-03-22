/*******************************************
 ***Problem: Longest Happy Prefix
 ***ID: 1392
 ***Judge: LeetCode
 ***Type: KMP preprocess step
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> preprocess(string &s){
        int i = 0, j = -1; 
        int n = s.size();
        vector<int> b(n + 1, 0);
        b[ 0 ] = -1;
        while( i < n ){
            while( j >= 0 && s[ i ] != s[ j ] ) j = b[ j ];
            i++; j++;
            b[ i ] = j;
        }
        return b;
    }  
    
    string longestPrefix(string s) {
        vector<int> b = preprocess(s);
        return s.substr(0, b[s.size()]);
    }
};
