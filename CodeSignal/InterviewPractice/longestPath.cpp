/*******************************************
 ***Problema: Longest Path
 ***Juez: CodeSignal
 ***Tipo: Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

int longestPath(std::string s) {
    if( s[0] != '\f' ) s = "\f" + s;
    s += "\f";
    int n = s.size();
    stack<int> S;
    int maximum = 0;
    int i = 0;
    while( i < n ){
        i++;
        //count tabs
        int tabs = 0;
        while( i < n && s[i] == '\t' ){
            i++;
            tabs++;
        }

        //count lenght of name
        int len = 0;
        bool isFile = false;
        while( i < n && s[i] != '\f'){
            len++;
            if( s[i] == '.') isFile = true;
            i++;
        }

        // backtrack depth
        while( !S.empty() && S.size() > tabs )
            S.pop();

        int total = 0;
        if( !S.empty() )
            total += S.top();
        
        total += len + 1;
        if( isFile)
            maximum = max( maximum, total - 1);
        S.push(total);
    }
    return maximum;
}
