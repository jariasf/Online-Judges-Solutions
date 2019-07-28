/*******************************************
 ***Problema: Alphabet Board Path
 ***ID: 1138
 ***Juez: LeetCode
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string alphabetBoardPath(string target) {
        int n = target.size();
        string res = "";
        int last_x = 0, last_y = 0;
        for( int i = 0 ; i < n ; ++i ){
            int index = target[i] - 'a';
            int x = index/5, y = index % 5;
            for( int j = last_y; j > y; --j)
                res += 'L';
            for( int j = last_x; j > x; --j)
                res += 'U';
            for( int j = last_y; j < y; ++j)
                res += 'R';
            for( int j = last_x; j < x; ++j)
                res += 'D';
            res += "!";
            last_x = x; last_y = y;
        }    
        return res;
    }
};
