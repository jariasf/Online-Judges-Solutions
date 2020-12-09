/*******************************************
 ***Problema: Can Place Flowers
 ***ID: Week1.5
 ***Juez: LeetCode
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:

    bool canPlaceFlowers(vector<int>& v, int n) {
        int sz = v.size();
        for( int i = 0 ; i < sz && n ; ++i ){
            if( v[i] == 0 ){
                int next = (i == sz - 1)?0:v[i + 1];
                int prev = (i == 0)?0:v[i - 1];                
                if( next == 0 && prev == 0 ){
                    n--;
                    v[i] = 1;
                }
            }
        }
        return n == 0;
    }
};
