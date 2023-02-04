/*******************************************
 ***Problema: Permutation in String
 ***ID: Week 1.4
 ***Juez: LeetCode
 ***Tipo: Sliding window - hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution{
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size(), total = s1.size();
        vector<int> hash(26);
        for( int i = 0 ; i < total ; ++i ) 
            hash[s1[i] - 'a']++;
        for( int i = 0, left = 0; i < n ; ++i ){
            hash[s2[i] - 'a']--;
            total--;
            while( hash[ s2[i] - 'a'] < 0 ){
                hash[s2[left++] - 'a']++;
                total++;
            }
            if( total == 0 ) return true;
        }
        return false;
    }
};
