/*******************************************
 ***Problema: Jewels and Stones
 ***ID: Week1.2
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<int> hash;
        int res = 0;
        for( int i = 0 ; i < J.size(); ++i ) hash.insert(J[i]);
        for( int i = 0 ; i < S.size(); ++i ) res += hash.find(S[i]) != hash.end();
        return res;
    }
};
