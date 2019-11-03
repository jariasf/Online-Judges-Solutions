/*******************************************
 ***Problema: Minimum Remove to Make Valid Parentheses
 ***ID: 1249
 ***Juez: LeetCode
 ***Tipo: Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        vector<bool> remove(n, false);
        vector<int> v;
        for( int i = 0 ; i < n ; ++i ){
            if( s[i] == '('){
                v.push_back(i);
            }else if( s[i] == ')'){
                if( v.size() == 0 ){
                    remove[i] = true;
                }else{
                    v.pop_back();
                }
            }
        }
        
        for( int i = 0 ; i < v.size(); ++i ){
            remove[ v[i] ] = true;
        }
        
        string res = "";
        for( int i = 0 ; i< n ; ++i ){
            if( !remove[i] ) res += s[i];
        }
        return res;
    }
};
