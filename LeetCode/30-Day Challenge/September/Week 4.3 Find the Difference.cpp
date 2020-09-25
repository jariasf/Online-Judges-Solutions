/*******************************************
 ***Problema: Find the Difference
 ***ID: Week4.3
 ***Juez: LeetCode
 ***Tipo: Bitmasks | Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    char findTheDifference(string s, string t) {
        int mask = 0;
        for(char c:s )
            mask ^= (c - 'a');
        for(char c:t )
            mask ^= (c - 'a');
        return (char)(mask + 'a');
    }
};
