/*******************************************
 ***Problem: Classify Strings
 ***Judge: CodeSignal
 ***Type: Greedy
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

bool isVowel(char c){
    string s = "aeiou";
    return s.find(c) != string::npos;
}

std::string classifyStrings(std::string s) {
    int n = s.size();
    bool good, bad;
    good = bad = false;
    int v = 0, c = 0;
    for( int i = 0 ; i < n ; ++i ){
        if( s[i] == '?' ){
            v++; c++;
        }else if( isVowel(s[i]) ){
            c = 0; v++;
        }else{
            v = 0; c++;
        }
        if( v == 3 || c == 5 ){
            bad = true;
        }
    }

    v = c = 0;
    good = true;
    for( int i = 0 ; i < n ; ++i ){
        if( s[i] == '?' ){
            if( v == 2 ){
                c = 1; v = 0;
            }else if( c == 4 ){
                c = 0; v = 1;
            }else{
                c = v = 0;
            }
        }else if( isVowel(s[i]) ){
            c = 0; v++;
        }else{
            v = 0; c++;
        }
        
        if( v == 3 || c == 5 ){
            good = false;
        }
    }

    if( good && bad ) return "mixed";
    else if( good ) return "good";
    return "bad";
}
//vv?cccc

