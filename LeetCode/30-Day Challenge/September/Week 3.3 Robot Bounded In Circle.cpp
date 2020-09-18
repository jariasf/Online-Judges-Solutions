/*******************************************
 ***Problema: Robot Bounded In Circle
 ***ID: Week3.3
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1 , 0};
    bool isRobotBounded(string s) {
        int x = 0, y = 0;
        int dir = 0;
        for( int i = 0 ; i < s.size(); ++i ){
            if( s[i] == 'G' ){
                x += dx[dir];
                y += dy[dir];
            }else if( s[i] == 'L')
                dir = (dir - 1 + 4) % 4;
            else
                dir = (dir + 1) % 4;
        }
        return (x == 0 && y == 0 || dir);
    }
};
