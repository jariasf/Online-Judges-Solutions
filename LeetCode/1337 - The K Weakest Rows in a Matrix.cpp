/*******************************************
 ***Problema: The K Weakest Rows in a Matrix
 ***ID: 1341
 ***Juez: LeetCode
 ***Tipo: Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int h = mat.size(), w = mat[0].size();
        vector<pair<int,int> > row;
        for( int i = 0 ; i < h ; ++i ){
            int index = 0;
            for( int j = 0 ; j < w ; ++j ){
                if( mat[i][j] == 1 ){
                    index = j + 1;
                }else
                    break;
            }
            row.push_back(make_pair(index, i));
        }
        
        sort(row.begin(), row.end());
        
        vector<int> res(k);
        for( int i = 0 ; i < k ; ++i ){
            res[i] = row[i].second;
        }
        return res;
    }
};
