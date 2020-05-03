/*******************************************
 ***Problema: Ransom Note
 ***ID: Week1.3
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> hash(26);
        for( int i = 0 ; i < magazine.size(); ++i ) 
            hash[magazine[i] - 'a']++;
        for( int i = 0 ; i < ransomNote.size(); ++i ){
            if( hash[ ransomNote[i] - 'a'] <= 0 ) 
                return false;
            hash[ ransomNote[i] - 'a']--;
        }
        return true;
    }
};
