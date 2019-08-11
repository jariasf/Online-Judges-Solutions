/*******************************************
 ***Problema: DI String Match
 ***ID: 942
 ***Juez: LeetCode
 ***Tipo: Ad hoc, Two Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> diStringMatch(string S) {
        int n = S.size();
        vector<int> seq(n + 1);
        int largest = n, smallest = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( S[i] == 'I' ){
                seq[i] = smallest++;
            }else{
                seq[i] = largest--;
            }
        }
        seq[n] = smallest;
        return seq;
    }
};
