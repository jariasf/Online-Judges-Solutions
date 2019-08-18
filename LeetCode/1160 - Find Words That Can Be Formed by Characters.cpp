/*******************************************
 ***Problema: Find Words That Can Be Formed by Characters 
 ***ID: 1160
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define MAX 30
    int countCharacters(vector<string>& words, string chars) {
        vector<int> hash(MAX, 0), aux;
        for( int i = 0 ; i < chars.size(); ++i ){
            hash[ chars[i] - 'a' ]++;
        }

        int result = 0;
        for( int i = 0 ; i < words.size(); ++i ){
            bool possible = true;
            aux = hash;
            for( int j = 0 ; j < words[i].size(); ++j ){
                if( aux[ words[i][j] - 'a'] > 0 ){
                    aux[ words[i][j] - 'a']--;
                }else{
                    possible = false;
                    break;
                }

            }
            if( possible ) result += words[i].size();
        }
        return result;
    }
};
