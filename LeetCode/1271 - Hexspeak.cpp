/*******************************************
 ***Problema: Hexspeak
 ***ID: 1271
 ***Juez: LeetCode
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string toHexspeak(string num) {
        long long n = stol(num);
        string res = "";
        while(n > 0){
            int d = n % 16;
            if( d == 0 ) res += "O";
            else if( d == 1 ) res += "I";
            else if( d >= 10 ) res += (char)(d - 10 + 'A');
            else return "ERROR";
            n/=16;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
