/*******************************************
 ***Problema: Remove K Digits
 ***ID: Week2.6
 ***Juez: LeetCode
 ***Tipo: Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<int> S;
        for( int i = 0 ; i < n ; ++i ){
            while( !S.empty() && S.top() > num[i] && k > 0 ){
                k--;
                S.pop();
            }
            if( !S.empty() || (S.empty() && num[i] != '0'))
                S.push(num[i]);
        }
        
        // if stack contains increasing digits
        while( !S.empty() && k > 0 ){
            S.pop(); k--;
        }
        
        if( S.size() == 0 ) return "0";

        string res = "";
        while( !S.empty() ){
            res += S.top(); S.pop();
        }            
        reverse(res.begin(), res.end());
        return res;
    }    
};
