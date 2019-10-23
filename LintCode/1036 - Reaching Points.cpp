/*******************************************
 ***Problema: Reaching Points
 ***ID: 1036
 ***Juez: LintCode
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(sx < tx && sy < ty ){
            if(ty > tx) ty %= tx;
            else tx %= ty;
        }
        if( sx == tx && sy <= ty && (ty - sy) % tx == 0 ) return true;
        return sy == ty && sx <= tx && (tx - sx) % ty == 0;
    }
};
