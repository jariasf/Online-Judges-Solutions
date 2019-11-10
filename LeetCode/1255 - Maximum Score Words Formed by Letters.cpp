/*******************************************
 ***Problema: Maximum Score Words Formed by Letters
 ***ID: 1255
 ***Juez: LeetCode
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> hash =  vector<int>(26);
        for( int i = 0 ; i < letters.size(); ++i )
            hash[letters[i] - 'a']++;
        
        int result = 0;
        int n = words.size();
        vector<int> aux;
        for( int i = 0 ; i < (1<<n) ; ++i ){
            bool valid = true;
            int sum = 0;
            aux = hash;
            for( int j = 0 ; j < n ; ++j ){
                if( (i & (1<<j)) ){
                    for( int k = 0 ; k < words[j].size(); ++k ){
                        if( aux[ words[j][k] - 'a' ] == 0 ){
                            valid = false;
                            break;
                        }
                        aux[ words[j][k] - 'a']--;
                        sum += score[ words[j][k] - 'a'];
                    }
                }
            }    
            if( valid ){
                result = max(result, sum);
            }
        }
        return result;
    }
};
