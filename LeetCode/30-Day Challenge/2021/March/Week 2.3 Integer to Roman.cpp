/*******************************************
 ***Problema: Integer to Roman
 ***ID: Week2.3
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string intToRoman(int num) {
        string roman[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int decimal[13] =  {1000,  900, 500,  400, 100,   90,  50,   40,  10,   9,    5,    4,   1};
        string romanvalue = "";
        for(int i = 0 ; i < 13 ; ++i ){
            while( num >= decimal[ i ] ){
                num -= decimal[ i ];
                romanvalue += roman[ i ];
            }
        }
        return romanvalue;
    }
};
