/*******************************************
 ***Problem: Maximal Square
 ***Judge: CodeSignal
 ***Type: Dynamic Programming
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

int maximalSquare(std::vector<std::vector<char>> matrix) {
    int h = matrix.size();
    if( h == 0 ) return 0;
    int w = matrix[0].size();
    if( w == 0 ) return 0;
    
    vector<vector<int> > dp(h + 1, vector<int>(w + 1, 0) );
    int maximum = 0;
    
    for( int i = 0 ; i < h ; ++i ){
        dp[i][0] = matrix[i][0] - '0';
        maximum = max(maximum, dp[i][0]);
    }
    for( int i = 0 ; i < w ; ++i ){
        dp[0][i] = matrix[0][i] - '0';
        maximum = max(maximum, dp[0][i]);    
    }

    for( int i = 1 ; i < h ; ++i ){
        for( int j = 1 ; j < w ; ++j ){
            if( matrix[i][j] == '1' ){
                int minimum = min( dp[i - 1][j], dp[i - 1][j - 1]);
                minimum = min( minimum, dp[i][j - 1]);
                dp[i][j] = minimum + 1;
                maximum = max( maximum, dp[i][j]);
            }
        }
    }

    return maximum * maximum;
}


