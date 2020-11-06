/*******************************************
 ***Problema: Minimum Height Trees
 ***ID: Week1.4
 ***Juez: LeetCode
 ***Tipo: Center of a Tree
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
	#define MAX 20005
	vector<int> ady[ MAX ];

	int Q[ MAX ] , prev[ MAX ];
	bool seen[ MAX ];
	int most_distant( int x, int V ){
		memset( seen , 0 , sizeof( seen ) );
		int tail = 1;
		Q[ 0 ] = x;
		prev[ x ] = -1;
		seen[ x ] =true;
		int large = 0;
		for( int i = 0 ; i < V ; ++i ){
		    int u = Q[ i ];
		    large = u;
		    for( int j = 0 ; j < ady[ u ].size(); ++j ){
		         if( !seen[ ady[ u ][ j ] ] ){
		             seen[ ady[ u ][ j ] ]= true;
		             prev[ ady[ u ][ j ] ] = u;
		             Q[ tail++ ] = ady[ u ][ j ];
		         }
		    }
		}
		return large;
	}

	vector<int> get_Center(int V){
		int large = most_distant( most_distant( 0, V ) , V );
		int aux = large, L = 0;
		while( aux != -1 ){
		    Q[ L++ ] = aux;
		    aux = prev[ aux ];
		}
		vector<int> ans;
		if( L & 1 ) ans.push_back(Q[L/2]);
		else{
		    ans.push_back(Q[ L/2]);
		    ans.push_back(Q[ L/2 - 1 ]);
		}
		return ans;
	}

    vector<int> findMinHeightTrees(int n, vector<vector<int> >& edges) {
        for( int i = 0 ; i <= n ; ++i ) ady[i].clear();
        int sz = edges.size();
        int u , v , w;
        for( int i = 0 ; i < sz ; ++i ){
            u = edges[i][0]; v = edges[i][1]; 
            ady[u].push_back(v);
            ady[v].push_back(u);
        }
        return get_Center(n);
    }
};
