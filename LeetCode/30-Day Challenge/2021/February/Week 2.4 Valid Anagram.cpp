/*******************************************
 ***Problema: Valid Anagram
 ***ID: Week2.4
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> hash;
        int len_s = s.size(), len_t = t.size();
        if( len_s != len_t ) return false;
        for( int i = 0 ; i < len_s ; ++i ){
            hash[s[i]]++;
        }
        
        for( int i = 0 ; i < len_t ; ++i ){
            hash[t[i]]--;
            if( hash[t[i]] < 0 ) return false;
        }
        return true;
    }
};
