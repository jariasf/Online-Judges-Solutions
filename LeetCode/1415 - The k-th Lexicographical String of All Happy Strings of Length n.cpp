/*******************************************
 ***Problem: The k-th Lexicographical String of All Happy Strings of Length n
 ***ID: 1415
 ***Judge: LeetCode
 ***Type: Recursion
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    string res;
    void solve(int n, int &k, LL cur, int last){
        if( k == 0 ) return;
        if( n == 0 ){
            k--;
            if( k == 0 ){
                res = to_string(cur);
                for( int i = 0 ; i < res.size() ; ++i ) 
                    res[i] = (char)( res[i] - '0' + 'a' - 1 );
            }
            return;
        }
        
        if( last == 0 ){
            for( int i = 1 ; i <= 3 ; ++i )
                solve(n - 1, k , cur * 10 + i, i);
            
        }else{
            for( int i = 1 ; i <= 3 ; ++i )
                if( i != last )
                    solve(n - 1, k , cur * 10 + i, i);
        }
    }
    
    string getHappyString(int n, int k) {
        res = "";
        solve(n, k, 0, 0);
        return res;
    }
};
