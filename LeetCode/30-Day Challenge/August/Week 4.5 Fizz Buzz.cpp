/*******************************************
 ***Problema: Fizz Buzz
 ***ID: Week4.5
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for( int i = 1 ; i <= n ; ++i ){
            if( i % 3 == 0 )
                res[i - 1] += "Fizz";
            if( i % 5 == 0 )
                res[i - 1] += "Buzz";
            if( res[i - 1].size() == 0 )
                res[i - 1] = to_string(i);
        }
        return res;
    }
};
