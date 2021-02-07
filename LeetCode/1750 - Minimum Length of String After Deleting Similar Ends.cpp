/*******************************************
 ***Problema: Minimum Length of String After Deleting Similar Ends
 ***ID: 1750
 ***Juez: LeetCode
 ***Tipo: Two Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while(left < right && s[left] == s[right]){
            char c = s[left];
            while( left <= right && s[left] == c) left++;
            while( left <= right && s[right] == c) right--;
        }
        return left > right ? 0: right - left + 1;
    }
};
