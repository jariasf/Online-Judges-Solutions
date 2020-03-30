/*******************************************
 ***Problem: Common Character Count 2
 ***Judge: CodeSignal
 ***Type: Hashing
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

int commonCharacterCount2(std::vector<std::string> s) {
    vector<vector<int> > hash(s.size(), vector<int>(26, 0));
    for( int i = 0 ; i < s.size(); ++i ){
        for( int j = 0 ; j < s[i].size(); ++j ){
            hash[i][s[i][j] - 'a']++;
        }
    }

    int cnt = 0;
    for( int i = 0 ; i < 26 ; ++i ){
        int mini = INT_MAX;
        for( int j = 0 ; j < s.size(); ++j ){
            mini = min( mini, hash[j][i]);
        }
        cnt += mini;
    }
    return cnt;
}
