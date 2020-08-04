/*******************************************
 ***Problema: Valid Palindrome
 ***ID: Week1.3
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0 , right = s.size() - 1;
        while( left <= right ){
            if( !isalnum(s[left]) )
                left++;
            
            if( !isalnum(s[right]))
                right--;

            if( isalnum(s[left]) && isalnum(s[right]) ){
                if( tolower(s[left]) != tolower(s[right]) )
                    return false;
                left++; right--;
            }
        }
        return true;
    }
};
