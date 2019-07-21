/*******************************************
 ***Problema: Number of Equivalent Domino Pairs
 ***ID: 5130
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        unordered_map<int, int> hash;
        int res = 0;
        for( int i = 0 ; i < n ; ++i ){
            vector<int> v = dominoes[i];
            if( v[0] > v[1]) swap(v[0], v[1]);
            res += hash[ v[0] * 10 + v[1]];
            hash[ v[0] * 10 + v[1]]++;          
        }
        return res;
    }
};
