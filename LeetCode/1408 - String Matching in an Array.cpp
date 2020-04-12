/*******************************************
 ***Problem: String Matching in an Array
 ***ID: 1408
 ***Judge: LeetCode
 ***Type: Brute Force
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool isSub(string &s1, string &s2 ){
        for( int i = 0 ; i < s2.size(); ++i ){
            int j = 0;
            for(  ; j < s1.size() && i + j < s2.size(); ++j ){
                if( s1[j] != s2[i + j] ) break;
            }
            if( j == s1.size() ) return true;
        }
        return false;
    }
    
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> res;
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < n ; ++j ){
                if( i !=j && isSub(words[i], words[j]) ){
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};
