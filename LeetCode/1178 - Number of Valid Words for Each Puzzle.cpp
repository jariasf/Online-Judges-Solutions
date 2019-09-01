/*******************************************
 ***Problema: Number of Valid Words for Each Puzzle
 ***ID: 1178
 ***Juez: LeetCode
 ***Tipo: Hashing + Bitmasks
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int n = words.size();
        unordered_map<int, int> hash;
        for( int i = 0 ; i < n ; ++i ){
            int mask = 0;
            for( int j = 0 ; j < words[i].size(); ++j ){
                mask |= 1<<(words[i][j] - 'a');
            }
            hash[mask]++;
        }

        int m = puzzles.size();
        vector<int> res(m);
        for( int i = 0 ; i <  m ; ++i ){
            for( int j = 0 ; j < (1<<7); ++j ){
                int sub = 0;
                for( int k = 0 ; k < 7 ; ++k ){
                    if( j & (1<<k) ){
                        sub |= 1<<(puzzles[i][k] - 'a');
                    }
                }
                if( sub & (1<<(puzzles[i][0] - 'a')) )
                  res[i] += hash[sub];
            }
        }
        return res;
    }
};
