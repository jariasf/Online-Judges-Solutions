/*******************************************
 ***Problema: Path Crossing
 ***ID: 1496
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool isPathCrossing(string path) {
        int n = path.size(), x = 0 , y = 0;
        unordered_map<int, unordered_set<int> > seen;
        seen[x].insert(y);
        for( int i = 0 ; i < n ; ++i ){
            if( path[i] == 'N' ) x--;
            else if( path[i] == 'E' ) y++;
            else if( path[i] == 'W') y--;
            else if( path[i] == 'S') x++;
            if( seen[x].find(y) != seen[x].end() ) return true;        
            seen[x].insert(y);
        }
        return false;
    }
};
