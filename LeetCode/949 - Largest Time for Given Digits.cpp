/*******************************************
 ***Problema: Largest Time for Given Digits
 ***ID: 949
 ***Juez: LeetCode
 ***Tipo: Brute force
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    string largestTimeFromDigits(vector<int>& A) {
        
        vector<int> p(4);
        p[0]=0;
        p[1] = 1;
        p[2] = 2;
        p[3] = 3;
        sort(A.begin(), A.end() );
        int maxi = -1;
        do{
            int h1 = A[p[0]];
            int h2 = A[p[1]];
            int m1 = A[p[2]];
            int m2 = A[p[3]];
            
            if( h1 == 2 ){
                if( h2 <= 3 && m1 <= 5 && m2 <= 9 ){
                    int time = (h1 * 10 + h2) * 60 + m1 * 10 + m2;
                    maxi = max( maxi, time );
                }
            }else if( h1 < 2 ){
                if( h2 <= 9 && m1 <= 5 && m2 <= 9 ){
                    int time = (h1 * 10 + h2) * 60 + m1 * 10 + m2;
                    maxi = max( maxi, time );
                }
            }
        }while(next_permutation(p.begin(), p.end() ));

        if( maxi == -1 ) return "";
        int h = maxi/60;
        int m = maxi % 60;
        string hh = to_string(h);
        string mm = to_string(m);
        if( hh.size() < 2 ) hh = "0" + hh;
        if( mm.size() < 2 ) mm = "0" + mm;
        return hh + ":" + mm;
    }

};
