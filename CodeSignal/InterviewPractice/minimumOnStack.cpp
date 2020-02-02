/*******************************************
 ***Problema: Minimum on stack
 ***Juez: CodeSignal
 ***Tipo: Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

std::vector<int> minimumOnStack(std::vector<std::string> operations) {
    stack<pair<int,int> > S;
    vector<int> res;
    for( int i = 0 ; i < operations.size(); ++i ){
        string op = operations[i];
        if( op[1] == 'u' ){
            int val = stoi(op.substr(5));
            int minimum = val;
            if( !S.empty() )
                minimum = min( minimum, S.top().second);
            S.push(make_pair(val, minimum));
        }else if( op[1] == 'o'){
            S.pop();
        }else{
            if( !S.empty())
                res.push_back(S.top().second);
        }
    }
    return res;
}

