/*******************************************
 ***Problema: Find Common Characters
 ***ID: 1002
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        for( int i = 0 ; i < 26 ; ++i ){
            int mini= 1<<30;
            for( int j = 0; j < A.size(); ++j ){
                int cnt = 0;
                for( int k = 0 ; k < A[j].size(); ++k ){
                    if( A[j][k] - 'a' == i ){
                        cnt++;
                    }
                }
                if( cnt > 0 )
                    mini = min( cnt, mini );
                else{
                    mini = 1<<30;
                    break;
                }
            }
            if( mini != 1<<30 ){
                for( int j = 0 ; j < mini ; ++j ){
                    res.push_back( string(1, (char) (i + 'a') ));
                }
            }
        }
        return res;
    }
};
