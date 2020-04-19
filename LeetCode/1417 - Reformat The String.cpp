/*******************************************
 ***Problem: Reformat The String
 ***ID: 1417
 ***Judge: LeetCode
 ***Type: Ad hoc
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string reformat(string s) {
        string digit = "";
        string letter = "";
        for( int i = 0 ; i < s.size(); ++i ){
            if( isdigit(s[i]) ) digit += s[i];
            else letter += s[i];
        }
        int n = digit.size(), m = letter.size();
        if( abs(n - m) > 1 ) return "";
        if( n > m ) swap(digit, letter);

        string res = "";        
        int i = 0;
        while( i < digit.size() ){
            res += letter[i];
            res += digit[i++];
        }
        if( i < letter.size() ) res += letter[i];
        return res;
    }
};
