/*******************************************
 ***Problema: Flower Planting With No Adjacent
 ***ID: 1042
 ***Juez: LeetCode
 ***Tipo: Graph Theory, Coloring
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define MAX 10005
    vector<int> ady[MAX];
    vector<int> color;
    void bfs( int origen ){
        queue< int > Q;
        Q.push( origen );
        color[ origen ] = 1;
        while( !Q.empty() ){
            int act = Q.front(); Q.pop();
            for( int i = 0 ; i < ady[ act ].size() ; ++i ){
                if( !color[ ady[ act ][ i ] ] ){
                    color[ ady[ act ][ i ] ] = ( color[ act ] + 1 ) % 4;
                    if( color[ ady[ act ][ i ] ] == 0 ) color[ ady[ act ][ i ] ] = 4;
                    Q.push( ady[ act ][ i ] );
                }
                else if( color[ ady[ act ][ i ] ] == color[ act ] ){
                    color[ ady[ act ][ i ] ] = ( color[ act ] + 1 ) % 4;
                    if( color[ ady[ act ][ i ] ] == 0 ) color[ ady[ act ][ i ] ] = 4;
                }
            }
        }
    }
    
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        int n = paths.size();
        for( int i = 0 ; i < MAX ; ++i ) ady[i].clear();
        for( int i = 0 ; i < n ; ++i ){
            int u = paths[i][0] - 1,v = paths[i][1] - 1;
            ady[u].push_back(v);
            ady[v].push_back(u);
        }
        
        color = vector<int>(N);
        for( int i = 0 ; i < N ; ++i ){
            if( color[i] == 0 ){
                bfs(i);
            }
        }
        return color;
    }
};
