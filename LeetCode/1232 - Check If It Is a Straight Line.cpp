/*******************************************
 ***Problema: Check If It Is a Straight Line
 ***ID: 1232
 ***Juez: LeetCode
 ***Tipo: Collinear Points
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        bool collinear = true;
        for( int i = 2 ; i < coordinates.size(); ++i ){
            int ox = coordinates[i - 2][0], oy = coordinates[i - 2][1];
            int px = coordinates[i - 1][0], py = coordinates[i - 1][1];
            int qx = coordinates[i][0],  qy = coordinates[i][1];
            int x1 = px - ox, y1 = py - oy, x2 = qx - ox, y2 = qy - oy;
            if( y2 * x1 != y1 * x2 ) return false;
        }
        return true;
    }
};
