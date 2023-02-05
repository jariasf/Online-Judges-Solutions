/*******************************************
 ***Problema: Find All Anagrams in a String
 ***ID: Week 1.5
 ***Juez: LeetCode
 ***Tipo: Sliding window - hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> hash(26);
        
        for(char c:p){
            hash[c - 'a']++;
        }
        
        int total = p.size();
        vector<int> res;
        
        for( int i = 0, left = 0 ; i < s.size(); ++i ){
            hash[s[i] - 'a']--;
            total--;
            
            while( hash[s[i] - 'a'] < 0 ){
                total++;
                hash[ s[left++] - 'a']++;
            }

            if( total == 0 ){
                res.push_back(left);
            }
        }
        return res;
    }
};
