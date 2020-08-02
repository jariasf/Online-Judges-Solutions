/*******************************************
 ***Problema: Count Good Triplets
 ***ID: 1534
 ***Juez: LeetCode
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int countGoodTriplets(vector<int>& v, int a, int b, int c) {
        int n = v.size();
        int res = 0;
        for( int i = 0 ; i < n ; ++i ){
            for( int j = i + 1 ; j < n ; ++j ){
                for( int k = j + 1 ; k < n ; ++k ){
                    if( abs(v[i] - v[j]) <= a && abs(v[j] - v[k]) <= b && abs(v[i] - v[k]) <= c)
                        res++;
                }
            }
        }
        return res;
    }
};
