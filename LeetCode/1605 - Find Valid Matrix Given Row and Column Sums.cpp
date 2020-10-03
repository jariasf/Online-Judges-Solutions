/*******************************************
 ***Problema: Find Valid Matrix Given Row and Column Sums
 ***ID: 1605
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int h = rowSum.size(), w = colSum.size();
        vector<vector<int> > res(h, vector<int>(w));
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( rowSum[i] > 0 && colSum[j] > 0){
                    int val = min(rowSum[i], colSum[j]);
                    res[i][j] = val;
                    rowSum[i] -= val;
                    colSum[j] -= val;
                }
            }
        }
        return res;
    }
};
