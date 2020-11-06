/*******************************************
 ***Problema: Minimum Cost to Move Chips to The Same Position
 ***ID: Week1.5
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n = position.size(), odd = 0, even = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( position[i] & 1 ) odd++;
            else even++;
        }
        return min(odd, even);
    }
};
