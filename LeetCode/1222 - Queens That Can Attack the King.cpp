/*******************************************
 ***Problema: Queens That Can Attack the King
 ***ID: 1222
 ***Juez: LeetCode
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define MAX 10
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int x = king[0], y = king[1];
        
        int seen[MAX][MAX] = {0};
        for( int i = 0 ; i < queens.size(); ++i ){
            seen[queens[i][0]][queens[i][1]] = 1;
        }
        vector<vector<int> > res;
        for( int i = -1 ; i <= 1; ++i ){
            for( int j = -1 ; j <= 1 ; ++j ){
                if( i == 0 && j == 0 ) continue;
                int k = 1;
                while( true ){
                    int nx = x + i * k, ny = y + j * k;
                    if( nx >= 0 && ny >= 0 && nx < 8 && ny < 8 ){
                        if( seen[nx][ny] ){
                            vector<int> v = {nx, ny};
                            res.push_back(v);
                            break;
                        }
                        k++;
                    }else
                        break;
                }
            }
        }
        return res;
    }
};
