/*******************************************
 ***Problema: Play with Chips
 ***ID: 1217
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int n = chips.size();
        int even = 0, odd = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( chips[i] & 1 ) odd++;
            else even++;
        }
        return min(even, odd);
    }
};
