/*******************************************
 ***Problema: Find the City With the Smallest Number of Neighbors at a Threshold Distance
 ***ID: 1334
 ***Juez: LeetCode
 ***Tipo: Floyd Warshall
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    #define MAX 101
    #define INF 9999999
    int ady[MAX][MAX];

    void Init(int V){
        for(int i = 0 ; i < MAX ; ++i ){
             for(int j = 0 ; j < MAX ; ++j ){
                     ady[ i ][ j ] = INF;
             }
            ady[ i ][ i ] = 0;
        }
    }

    void floyd(int V){
        for(int k = 0 ; k < V ; ++k ){
            for(int i = 0 ; i < V ; ++i ){
                 for(int j = 0 ; j < V ; ++j ){
                        int t = ady[ i ][ k ] + ady[ k ][ j ];
                        if( t < ady[ i ][ j ] ){
                            ady[ i ][ j ] = t;
                        }
                 }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        Init(n);        
        for( int i = 0 ; i < edges.size(); ++i ){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            ady[u][v] = ady[v][u] = w;
        }
        
        floyd(n);
        
        int minimum = 1<<30;
        int index = 0;
        for( int i = 0 ; i < n ; ++i ){
            int cities = 0;
            for( int j = 0; j < n ; ++j ){
                if( i == j ) continue;
                if( ady[i][j] <= distanceThreshold ) cities++;
            }
            if( minimum >= cities ){
                minimum = cities;
                index = i;
            }
        }
        
        return index;
    }
};
