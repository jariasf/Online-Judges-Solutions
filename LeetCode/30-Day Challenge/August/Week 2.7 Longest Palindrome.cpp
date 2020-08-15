/*******************************************
 ***Problema: Longest Palindrome
 ***ID: Week2.7
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> hash(125);
        for( char c: s )
            hash[c]++;
        
        int res = 0;
        bool odd = false;
        for(int val:hash ){
            if(val > 0){
                if(val % 2 == 0)
                    res += val;
                else{
                    res += val - 1;
                    odd = true;
                }
            }
        }
        return res + odd;
    }
};
