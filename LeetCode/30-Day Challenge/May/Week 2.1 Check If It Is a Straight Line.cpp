/*******************************************
 ***Problema: Check If It Is a Straight Line
 ***ID: Week2.1
 ***Juez: LeetCode
 ***Tipo: Vector scaling verification (Cross-Product)
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        for( int i = 1 ; i < n ; ++i ){
            coordinates[i][0] -= coordinates[0][0];
            coordinates[i][1] -= coordinates[0][1];
        }
        coordinates[0][0] = coordinates[0][1] = 0;
        
        for( int i = 2; i < n ; ++i )
            if( coordinates[i][0] * coordinates[1][1] != coordinates[i][1] * coordinates[1][0] )
                return false;
        return true;
    }
};
