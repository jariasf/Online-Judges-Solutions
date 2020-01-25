/*******************************************
 ***Problema: Sort the Matrix Diagonally
 ***ID: 1329
 ***Juez: LeetCode
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int h = mat.size(), w = mat[0].size();
        
        vector<int> aux;
        
        for( int j = 0 ; j < w ; ++j ){
            aux.clear();
            for( int k = 0 ; k < h && j + k < w ; ++k ){
                aux.push_back(mat[k][j+k]);
            }
            sort(aux.begin(), aux.end());
            for( int k = 0 ; k < h && j + k < w ; ++k ){
                mat[k][j+k] = aux[k];
            }
        }
        
        for( int i = 1; i < h ; ++i ){
            aux.clear();
            
            for( int k = 0; i + k < h && k < w ; ++k ){
                aux.push_back(mat[i+k][k]);
            }
            sort(aux.begin(), aux.end());
            for( int k = 0; i + k < h && k < w ; ++k ){
                mat[i+k][k] = aux[k];
            }
        }
        
        return mat;
    }
};
