/*******************************************
 ***Problem: Reverse In Parentheses
 ***Judge: CodeSignal
 ***Type: Stack
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

std::string reverseInParentheses(std::string s) {
    stack<string> S;
    s = "(" + s + ")";
    int n = s.size();
    for( int i = 0 ; i < n ; ++i ){
        if( s[i] == ')'){
            string aux = "";
            while( !S.empty() ){
                if( S.top()[0] != '('){
                    aux += S.top();
                    S.pop();
                }else{
                    S.pop();
                    break;
                }
            }
            if( aux.size() > 0 ){
                reverse(aux.begin(), aux.end());
                S.push(aux);
            }
        }else
            S.push(string(1,s[i]));
    }
    if( S.empty() ) return "";
    return S.top();
}



