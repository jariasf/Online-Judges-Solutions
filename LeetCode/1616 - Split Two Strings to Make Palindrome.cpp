/*******************************************
 ***Problema: Split Two Strings to Make Palindrome
 ***ID: 1616
 ***Juez: LeetCode
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
   
    bool isPalindrome(string &s, int left, int right){
        while( left < right ){
            if( s[left] != s[right]) return false;
            left++; right--;
        }
        return true;
    }
    
    bool check(string &a, string &b ){
        int n = a.size(), left = 0, right = n - 1;
        while( left < right && a[left] == b[right] ){
            left++; right--;
        }
        return isPalindrome(a, left, right) || isPalindrome(b, left, right);
    }
    
    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }
};
