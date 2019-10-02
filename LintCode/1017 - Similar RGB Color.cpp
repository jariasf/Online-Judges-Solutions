/*******************************************
 ***Problema:Similar RGB Color
 ***ID: 1017
 ***Juez: LintCode
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param color: the given color
     * @return: a 7 character color that is most similar to the given color
     */
    int toDecimal(char a, char b){
        int decimal = 0;
        if( a >= '0' && a <= '9') decimal = a - '0';
        else decimal = a - 'a' + 10; 
        decimal *= 16;
        if( b >= '0' && b <= '9') decimal += b - '0';
        else decimal += b - 'a' + 10; 
        return decimal;
    } 
     
    string similarRGB(string &color) {
        vector<int> possibilities;
        for( int i = 0 ; i < 16 ; ++i )
            possibilities.push_back(i * 16 + i);

        string res = "#";
        int n = possibilities.size();
        for( int i = 1 ; i < color.size() ; i += 2 ){
            int decimal = toDecimal(color[i], color[i + 1]);
            int minimum = 1<<30, min_index = 0;
            for( int j = 0 ; j < n ; ++j ){
                int distance = abs(decimal - possibilities[j]);
                if( minimum > distance ){
                    minimum = distance;
                    min_index = j;
                }
            }
            char digit = (min_index < 10 ? min_index + '0' : min_index - 10 + 'a');
            res += string(1, digit) + string(1, digit);
        }
        return res;
    }
};
