/*******************************************
 ***Problema: Next Greater Element III
 ***ID: Week4.2
 ***Juez: LeetCode
 ***Tipo: Next Permutation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if( next_permutation(s.begin(), s.end()) ){
            long long num = stol(s);
            if( num > INT_MAX ) return -1;
            return num;
        }
        return -1;
    }
};
