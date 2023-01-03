/*******************************************
 ***Problema: Delete Columns to Make Sorted
 ***ID: Week 1.3
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        int res = 0;
        for(int j = 0; j < m ; ++j){
            for(int i = 1 ; i < n ; ++i){
                if( strs[i][j] < strs[i - 1][j]){
                    res++;
                    break;
                }
            }
            
        }
        return res;
    }
};
