/*******************************************
 ***Problema: Simplify Path
 ***ID: Week1.5
 ***Juez: LeetCode
 ***Tipo: Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        vector<string> S;
        int length = path.size();
        int index = 1;
        while( index < length ){
            int next = path.find("/", index);
            string token = path.substr(index, next - index);
            if( token == ".."){
                if( !S.empty() )
                    S.pop_back();
            }else if( token != "." && token.size() > 0 ){
                S.push_back(token);
            }
            index = next + 1;
        }
        string result = "";
        for( int i = 0 ; i < S.size() ; ++i ){
            result.append( "/" + S[i] );
        }
        if( result.size() == 0 ) return "/";
        return result;
    }
};
