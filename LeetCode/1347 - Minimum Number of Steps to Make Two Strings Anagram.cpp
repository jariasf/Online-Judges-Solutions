/*******************************************
 ***Problem: Minimum Number of Steps to Make Two Strings Anagram
 ***ID: 1347
 ***Judge: LeetCode
 ***Type: Hashing
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

//Using one hash table
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> hash_s(26, 0);
        for( int i = 0 ; i < s.size(); ++i )
            hash_s[s[i] - 'a']++;
        
        int res = 0;
        for( int i = 0 ; i < t.size() ; ++i )
            if( --hash_s[t[i] - 'a'] < 0 ) 
                res++;
        return res;
    }
};


//Using two hash tables
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> hash_s(26, 0);
        vector<int> hash_t(26, 0);
        
        for( int i = 0 ; i < s.size(); ++i ){
            hash_s[s[i] - 'a']++;
        }

        for( int i = 0 ; i < t.size(); ++i ){
            hash_t[t[i] - 'a']++;
        }
        
        int res = 0;
        for( int i = 0 ; i < 26 ; ++i ){
            if( hash_s[i] > hash_t[i]) res += hash_s[i] - hash_t[i];
        }
        return res;
    }
};
