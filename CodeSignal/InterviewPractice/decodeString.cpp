/*******************************************
 ***Problema: DecodeString
 ***Juez: CodeSignal
 ***Tipo: Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

std::string decodeString(std::string s) {
    int n = s.size();
    stack<pair<int, int> > S;
    int cnt = 0;
    string res = "";
    for( int i = 0 ; i < n ; ++i ){
        if( s[i] == '['){
            S.push(make_pair(i, cnt));
            cnt = 0;
        }else if( s[i] == ']'){
            auto& p = S.top();
            p.second--;
            if( p.second == 0 ) 
                S.pop();
            else
                i = p.first;
        }else if( isdigit(s[i]) ){
            cnt = cnt * 10 + s[i] - '0';            
        }else{
            res += s[i];
        }
    }
    return res;
}
