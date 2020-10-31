/*******************************************
 ***Problema: Remove Duplicate Letters
 ***ID: Week2.4
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> hash(256, 0);
        vector<bool> visited(256, false);
        string res = " ";        
        for( char c : s )
            hash[c]++;

        for( char c : s ) {
            hash[c]--;
            if( visited[c] ) continue;
            while( c < res.back() && hash[res.back()] ) {
                visited[res.back()] = false;
                res.pop_back();
            }
            res += c;
            visited[c] = true;
        }
        return res.substr(1);
    }
};
