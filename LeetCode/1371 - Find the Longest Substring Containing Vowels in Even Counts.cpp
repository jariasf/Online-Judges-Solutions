/*******************************************
 ***Problem: Find the Longest Substring Containing Vowels in Even Counts
 ***ID: 1371
 ***Judge: LeetCode
 ***Type: Bitmasks
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        int mask = 0;
        vector<int> seen(33, -1);
        int result = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( s[i] == 'a' ) mask ^= 1;
            if( s[i] == 'e' ) mask ^= 2;
            if( s[i] == 'i' ) mask ^= 4;
            if( s[i] == 'o' ) mask ^= 8;
            if( s[i] == 'u' ) mask ^= 16;
            if( mask && seen[mask] == -1 ) seen[mask] = i;
            result = max(result, i - seen[mask]);
        }
        return result;
    }
};
