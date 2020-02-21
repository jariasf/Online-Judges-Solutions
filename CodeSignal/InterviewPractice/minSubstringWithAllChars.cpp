/*******************************************
 ***Problema: Minimum Substring With All Chars
 ***Juez: CodeSignal
 ***Tipo: Sliding Window
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

bool valid(vector<int> &cnt, string &t ){
    for( int i = 0 ; i < t.size(); ++i ){
        if( cnt[t[i] - 'a'] == 0 ) return false;
    }
    return true;
}

std::string minSubstringWithAllChars(std::string s, std::string t) {
    if( t.size() == 0 ) return "";
    vector<int> cnt(26,0);
    int n = s.size();
    int minimum = 1<<30, min_index = -1;
    for( int left = 0 , right = 0; right < n ; ++right ){
        cnt[ s[right] - 'a']++;  
        if( valid(cnt, t) ){
            do{
                int tmp = right - left + 1;
                if( tmp < minimum ){
                    minimum = tmp;
                    min_index = left;
                }

                cnt[ s[left] - 'a']--;
                left++;
                
            }while( left <= right && valid(cnt, t));
            left--;
            cnt[ s[left] - 'a']++;
        }
    }
    if( min_index == -1 ) return "";
    return s.substr(min_index, minimum);
}
