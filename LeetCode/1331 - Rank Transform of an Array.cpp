/*******************************************
 ***Problema: Rank Transform of an Array
 ***ID: 1331
 ***Juez: LeetCode
 ***Tipo: Hashing + Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> hash;
        int n = arr.size();
        for( int i = 0 ; i < n ; ++i ){
            hash[ arr[i] ] = 0;
        }
        
        int r = 1;
        for( auto &it: hash ){
            it.second = r++;
        }
        vector<int> res(n);
        for( int i = 0 ; i < n ; ++i ){
            res[i] = hash[ arr[i] ];
        }
        return res;
    }
};
