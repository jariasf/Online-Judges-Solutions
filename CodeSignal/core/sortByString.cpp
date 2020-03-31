/*******************************************
 ***Problem: Sort By String
 ***Judge: CodeSignal
 ***Type: Hashing + Sorting
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

std::string sortByString(std::string s, std::string t) {
    vector<int> hash(26);
    vector<char> hash2(26);
    for( int i = 0 ; i < t.size(); ++i ){
        hash[t[i] - 'a'] = i;
        hash2[i] = t[i];
    }    

    vector<int> indices(s.size());
    for( int i = 0 ; i < s.size(); ++i ){
        indices[i] = hash[s[i] - 'a'];
    }
    sort(indices.begin(), indices.end());

    string res = "";
    for( int i = 0 ; i < indices.size(); ++i ){
        res += hash2[indices[i]];
    }
    return res;
}

