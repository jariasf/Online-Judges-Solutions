/*******************************************
 ***Problema: Break a Palindrome
 ***ID: 1328
 ***Juez: LeetCode
 ***Tipo: Simulation + Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool isPal(string &s){
        int left = 0, right = s.size();
        while( left < right ){
            if( s[left] != s[right - 1]) return false;
            left++;
            right--;
        }
        return true;
    }
    
    string breakPalindrome(string s) {
        int n = s.size();
        set<string> hash;
        for( int i = 0 ; i < n ; ++i ){
            int v = s[i] - 'a';
            char tmp = s[i];
            for( int j = 0 ; j < 2 ; ++j ){
                s[i] = (char)(j + 'a');
                if( !isPal(s) ){
                    hash.insert(s);
                }
            }
            s[i] = tmp;
        }
        
        if( hash.size() == 0 ) return "";
        return *hash.begin();
    }
};
