/*******************************************
 ***Problema: First Unique Character in a String
 ***ID: Week1.5
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> hash;
        for( auto c: s)
            hash[c]++;
        for( int i = 0 ; i < s.size(); ++i )
            if( hash[s[i]] == 1 ) 
                return i; 
        return -1;
    }
};
