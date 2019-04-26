/*******************************************
 ***Problema: Number of Enclaves
 ***ID: 1020
 ***Juez: LeetCode
 ***Tipo: Graph Theory - BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define mp make_pair
    #define pii pair<int,int>
    int dx[4] = {0, 0 ,1, -1};
    int dy[4] = {1, -1, 0 , 0 };
    
    int numEnclaves(vector<vector<int>>& A) {
        int h = A.size();
        int w = A[0].size();
        queue<pii> Q;
        for( int i = 0 ; i < w ; ++i ){
            if( A[0][i] == 1 ){
                Q.push( mp(0,i) );
                A[0][i] = -1;
            }
            if( A[h - 1][i] == 1 ){
                Q.push( mp(h - 1, i) );
                A[h - 1][i] = -1;
            }
        }
        
        for( int i = 0 ;i < h ; ++i ){
            if( A[i][0] == 1 ){
                Q.push( mp(i, 0) );
                A[i][0] = - 1;
            }
            if( A[i][w - 1] == 1 ){
                Q.push(mp(i, w- 1));
                A[i][w - 1] = -1;
            }
        }
        
        while( !Q.empty() ){
            pii p = Q.front(); Q.pop();
            int x = p.first, y = p.second;
            for( int i = 0 ; i < 4 ; ++i ){
                int nx = dx[i] + x, ny = dy[i] + y;
                if( nx >= 0 && ny >= 0 && nx < h && ny < w && A[nx][ny] == 1 ){
                    A[nx][ny] = -1;
                    Q.push( mp(nx,ny));
                }
            }
        }
        
        int result = 0;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( A[i][j] == 1 ){
                    result++;
                }
            }
        }
        return result;
    }
};
