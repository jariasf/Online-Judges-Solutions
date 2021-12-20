/*******************************************
 ***Problema: Find First Palindromic String in the Array
 ***ID: 2108
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string s: words){
            string rev = s;
            reverse(rev.begin(), rev.end());
            if( s == rev ) return s;
        }
        return "";
    }
};
