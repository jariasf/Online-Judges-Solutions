/*******************************************
 ***Problema: Flip Columns For Maximum Number of Equal Rows
 ***ID: 1072
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

//Using map
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map< vector<int>, int > hash;
        for( int i = 0 ; i < matrix.size(); ++i ){
            hash[ matrix[i] ]++;
            for( int j = 0 ; j < matrix[i].size(); ++j ){
                matrix[i][j] = !matrix[i][j];
            }
            hash[ matrix[i] ]++;
        }

        int result = 0;
        for( auto it: hash ){
            result = max( result, it.second);
        }
        return result;
    }   
};


//Using 2 strings and unordered_map
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> hash;
        for( int i = 0 ; i < matrix.size(); ++i ){
            string current = "", flip = "";
            for( int j = 0 ; j < matrix[i].size(); ++j ){
                current += (char)(matrix[i][j] + '0');
                flip += (char)(!matrix[i][j] + '0');
            }
            hash[current]++;
            hash[flip]++;
        }
        int result = 0;
        
        for( auto it: hash ){
            result = max( result, it.second);
        }
        return result;
    }   
};

//Using 1 string and unordered_map
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> hash;
        for( int i = 0 ; i < matrix.size(); ++i ){
            string current = "";
            for( int j = 0 ; j < matrix[i].size(); ++j ){
                if( matrix[i][j] == matrix[i][0] ) current += '1';
                else current += '0';
            }
            hash[current]++;
        }

        int result = 0;
        for( auto it: hash ){
            result = max( result, it.second);
        }
        return result;
    }   
};
