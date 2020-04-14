/*******************************************
 ***Problema: Perform String Shifts
 ***ID: Week2.5
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int cnt = 0;
        int n = s.size();
        for( int i = 0 ; i < shift.size(); ++i ){
            cnt += (shift[i][0] == 0 ) ? shift[i][1]: -shift[i][1];
        }
        if( cnt < 0 ){
            cnt = -(-cnt % n);
        }
        cnt = (cnt + n ) % n;
        rotate(s.begin(), s.begin() + cnt , s.end() );
        return s;
    }
};
