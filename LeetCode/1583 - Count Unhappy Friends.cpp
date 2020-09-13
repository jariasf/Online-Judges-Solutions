/*******************************************
 ***Problema: Count Unhappy Friends
 ***ID: 1583
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& p, vector<vector<int>>& pairs) {
        vector<vector<int> > hash(n, vector<int>(n, -1));
        for( int i = 0 ;i < p.size(); ++i ){
            for( int j = 0 ; j < p[i].size(); ++j ){
                hash[i][ p[i][j] ] = j;
            }
        }
        
        int res = 0, m = pairs.size();
        vector<bool> seen(n , 0);
        for( int i = 0 ; i < m ; ++i ){
            for( int j = 0; j < m ; ++j ){
                if( i != j ){
                    int x = pairs[i][0], y = pairs[i][1];
                    int u = pairs[j][0], v = pairs[j][1];
                    if( hash[x][u] < hash[x][y] && hash[u][x] < hash[u][v] )
                        seen[x] = true;
                    if( hash[x][v] < hash[x][y] && hash[v][x] < hash[v][u] )
                        seen[x] = true;                    
                    if( hash[y][u] < hash[y][x] && hash[u][y] < hash[u][v] )
                        seen[y] = true;
                    if( hash[y][v] < hash[y][x] && hash[v][y] < hash[v][u] )
                        seen[y] = true;                                        
                }
            }
        }
        
        for( int i = 0 ; i < n ; ++i )
            res += seen[i];
        return res;
    }
};
