/*******************************************
 ***Problema: Number of Burgers with No Waste of Ingredients
 ***ID: 1276
 ***Juez: LeetCode
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> res;
        int d = tomatoSlices - 2 * cheeseSlices;
        if( d % 2 != 0 || d < 0 ) return res;
        int y = d / 2;
        int x = cheeseSlices - y;  
        if( x < 0 ) return res;
        res = {y , x};
        return res;
    }
};
