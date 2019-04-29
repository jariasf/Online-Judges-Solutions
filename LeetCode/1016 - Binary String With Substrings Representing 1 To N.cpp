/***************************************************************
 ***Problema: Binary String With Substrings Representing 1 To N
 ***ID: 1016
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 ***************************************************************/

class Solution {
public:
    typedef long long LL;
    bool queryString(string S, int N) {
        int n = S.size();
        unordered_set<LL> hash;
        for( int i = 0 ; i < n ; ++i ){
            LL sub = 0;
            for( int j = i, k = 0 ; j < n && k < 32 ; ++j, ++k ){
                sub <<= 1;
                if( S[j] == '1' ){
                    sub |= 1;
                }
                if( sub <= N && sub > 0)
                    hash.insert(sub);
            }
            
        }
        return hash.size() == N;
    }
};
