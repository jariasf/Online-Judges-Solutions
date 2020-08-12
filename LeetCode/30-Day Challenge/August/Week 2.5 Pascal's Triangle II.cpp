/*******************************************
 ***Problema: Pascal's Triangle II
 ***ID: Week2.5
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for( int i = 1 ; i <= rowIndex ; ++i ){
            int last = res[0], cur;
            for( int j = 1 ; j <= i ; ++j ){
                cur = res[j];
                res[j] = last + res[j];
                last = cur;
            }
        }
        return res;
    }
};
