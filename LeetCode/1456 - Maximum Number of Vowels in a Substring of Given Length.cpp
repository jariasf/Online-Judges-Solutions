/*******************************************
 ***Problema: Maximum Number of Vowels in a Substring of Given Length
 ***ID: 1456
 ***Juez: LeetCode
 ***Tipo: Sliding Window
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int n = s.size();
        
        int cnt = 0, maxi = 0;
        for( int i = 0 ; i < k ; ++i )
            if( isVowel(s[i])) cnt++;
        
        maxi = cnt;
        for( int left = 0,right = k; right < n ; ++right ){
            if( isVowel(s[left++])) cnt--;
            if( isVowel(s[right]) ) cnt++;
            maxi = max( maxi, cnt);
        }
        return maxi;
        
    }
};
