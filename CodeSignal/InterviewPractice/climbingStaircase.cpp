/*******************************************
 ***Problema: Climbing Staircase
 ***Juez: CodeSignal
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

std::vector<std::vector<int>> climbingStaircase(int n, int k) {
    if( n == 0 )
        return {{}};
    vector<vector<int> > res;
    for( int i = 1 ; i <= k && n - i >= 0 ; ++i ){
        vector<vector<int> > cur = climbingStaircase(n - i, k);
        for( int j = 0 ; j < cur.size(); ++j ){
            vector<int> tmp = cur[j];
            if( tmp.size() == 0 )
                tmp = {i};
            else
                tmp.insert(tmp.begin(), i);
            res.push_back(tmp);
        }
    }
    return res;
}

