/*******************************************
 ***Problema: Find N Unique Integers Sum up to Zero
 ***ID: 1304
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n);
        int start = 0;
        int mid;
        if( n & 1){
            start = 1;
            mid = (n - 1)/2;
        }else
            mid = n/2;
        for( int i = 0; i < mid ; ++i, ++start)
            res[start] = (i + 1);

        for( int i = 0 ; i < mid ; ++i, ++start )
            res[start] = -(i + 1);
        
        return res;
    }
};
