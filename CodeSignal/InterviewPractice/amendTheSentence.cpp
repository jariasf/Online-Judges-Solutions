/*******************************************
 ***Problem: Amend The Sentence
 ***Judge: CodeSignal
 ***Type: Simulation
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

std::string amendTheSentence(std::string s) {
    int n = s.size();
    string res = "";
    for( int i = 0 ; i < n ; ++i ){
        if( s[i] >= 'A' && s[i] <= 'Z'){
            if( res.size() > 0 ) res += " ";
            res += s[i] - 'A' + 'a';
        }else
            res += s[i];
    }
    return res;
}

