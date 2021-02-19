/*******************************************
 ***Problema: Letter Case Permutation
 ***ID: Week3.2
 ***Juez: LeetCode
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    void permute(vector<string> &permutations, int pos, string &s){
        if( pos == s.size() ){
            permutations.push_back(s);
            return;
        }
        
        if( isalpha(s[pos]) ){
            s[pos] ^= 32;
            permute(permutations, pos + 1, s);
            s[pos] ^= 32;
        }
        permute(permutations, pos + 1, s );
    }
    
    vector<string> letterCasePermutation(string S) {
        vector<string> permutations;        
        permute(permutations, 0, S);
        return permutations;
    }
};
