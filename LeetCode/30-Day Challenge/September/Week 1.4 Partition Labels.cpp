/*******************************************
 ***Problema: Partition Labels
 ***ID: Week1.4
 ***Juez: LeetCode
 ***Tipo: Two Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> result;
        vector<int> max_index;
        max_index = vector<int>(26, -1);
        for( int i = 0 ; i < S.size() ; ++i ){
            max_index[ S[i] - 'a'] = i;
        }
        
        int current_index = 0, size = 0;
        while( current_index < S.size() ){
            size = max_index[ S[current_index]- 'a'];
            for( int i = current_index; i <= size; ++i ){
                size = max(size, max_index[ S[i] - 'a']);
            }
            result.push_back(size - current_index + 1);
            current_index = size + 1;
        }
        return result;
    }
};
