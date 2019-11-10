/*******************************************
 ***Problema: Reconstruct a 2-Row Binary Matrix
 ***ID: 1253
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int> > res(2, vector<int>(n, 0));
        for( int i = 0 ; i < n ; ++i ){
            if( colsum[i] == 2 ){
                res[0][i] = res[1][i] = 1;
                upper--; lower--;
            }
        }
        if( upper < 0 || lower < 0 ) return vector<vector<int>>();
        for( int i = 0 ; i < n ; ++i ){
            if( colsum[i] == 1 ){
                if( upper > 0 ){
                    res[0][i] = 1;
                    upper--;
                }else if( lower > 0 ){
                    res[1][i] = 1;
                    lower--;
                }else{
                    return vector<vector<int>>();
                }
            }
        }
        if( upper != 0 || lower != 0 ) return vector<vector<int> >();
        return res;
    }
};
