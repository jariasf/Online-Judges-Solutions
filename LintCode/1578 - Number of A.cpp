/*******************************************
 ***Problema: Number of A
 ***ID: 1578
 ***Juez: LintCode
 ***Tipo: Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param s: the given string
     * @return: the number of A
     */
     
    int val(char c){
        if( c == 'B') return 0;
        if( c == 'A') return 1;
        if( c == 'C') return 2;
        return 3;
    } 
     
    int lowerBound(string &s){
        int left = 0, right = s.size();
        while( left < right ){
            int mid = (left + right)/2;
            if( val(s[mid]) < val('A') ){
                left = mid + 1;
            }else
                right = mid;
        }
        if( right == s.size() || s[right] != 'A' ) return 0;
        return right;
    } 
     
    int upperBound(string &s){
        int left = 0, right = s.size();
        while( left < right ){
            int mid = (left + right)/2;
            if( val(s[mid]) <= val('A') ){
                left = mid + 1;
            }else
                right = mid;
        }
        if( left - 1 < 0 || s[left - 1] != 'A' ) return 0;
        return left;
    }     
     
    int countA(string &s) {
        return upperBound(s) - lowerBound(s);
    }
};
