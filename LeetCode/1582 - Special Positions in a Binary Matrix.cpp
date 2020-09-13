/*******************************************
 ***Problema: Special Positions in a Binary Matrix
 ***ID: 1582
 ***Juez: LeetCode
 ***Tipo: Brute Force || Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// time: O(n^2), space: O(n)
class Solution {
public:
    int numSpecial(vector<vector<int>>& v) {
        int cnt = 0;
        int h = v.size(), w = v[0].size();
        vector<int> rows(h), cols(w);
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( v[i][j] ){
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( v[i][j] && rows[i] == 1 && cols[j] == 1 )
                    cnt++;
            }
        }
        
        return cnt;
    }
};


// time: O(n^3), space: O(1)
class Solution {
public:
    int numSpecial(vector<vector<int>>& v) {
        int cnt = 0;
        int h = v.size(), w = v[0].size();
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( v[i][j] == 1 ){
                    bool b = true;
                    for( int k = 0 ; k < w ; ++k ){
                        if( k != j && v[i][k] == 1 ){
                            b = false;
                            break;
                        }
                    }
                    if( b ){
                        for( int k = 0 ; k < h ; ++k ){
                            if( i != k && v[k][j] == 1 ){
                                b = false;
                                break;
                            }
                        }
                    }
                    cnt += b;
                }
            }
        }
        return cnt;
    }
};
