/*******************************************
 ***Problema: Greatest Common Divisor of Strings
 ***ID: 1071
 ***Juez: LeetCode
 ***Tipo: GCD
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if( str1.size() < str2.size() )
            swap(str1, str2);
        if( str1 == str2 ) return str1;
        if( str1.substr(0, str2.size()) == str2 ){
            return gcdOfStrings(str2, str1.substr(str2.size(), str1.size() - str2.size()));
        }
        return "";
    }
};
