/*******************************************
 ***Problema: Transform to Chessboard
 ***ID: 1034
 ***Juez: LintCode
 ***Tipo: Array Manipulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minSteps(vector<int> &v){
        int n = v.size();
        int odd = 0, even = 0;
        for( int i = 0 ; i < n; ++i ){
            if( v[i] == 1 ){
                if( i & 1 ) even++;
                else odd++;
            }
        }
        int ones = odd+even, zeros = n - ones;
        if( abs(ones - zeros) > 1 ) return -1;
        if( n & 1 ){
            if( ones > zeros ) return even;
            return odd;
        }
        return min(odd, even);
    }
    
    int movesToChessboard(vector<vector<int>> &board) {
        int steps = -1;
        int n = board.size();
        for( int i = 0 ; i < n - 1 ; ++i ){
            for( int j = 0 ; j < n - 1 ; ++j ){
                if( board[i][j] ^ board[i + 1][j] ^ board[i][j + 1] ^ board[i + 1][j + 1] != 0 ){
                    return -1;
                }
            }
        }
        vector<int> column(n);
        for( int i = 0 ; i < n ; ++i )
            column[i] = board[i][0];
        steps = minSteps(board[0]);
        if( steps < 0 ) return -1;
        steps += minSteps(column);
        if( steps < 0 ) return -1;        
        return steps;
    }
};
