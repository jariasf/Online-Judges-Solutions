/*******************************************
 ***Problem: Squares Under Queen Attack
 ***Judge: CodeSignal
 ***Type: Hashing
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

bool found(unordered_set<int> &hash, int val ){
    return hash.find(val) != hash.end();
}

std::vector<bool> squaresUnderQueenAttack(int n, std::vector<std::vector<int>> queens, std::vector<std::vector<int>> queries) {
    unordered_set<int> row, col, left_diag, right_diag;
    for( int i = 0 ; i < queens.size(); ++i ){
        int x = queens[i][0], y = queens[i][1];
        row.insert(x);
        col.insert(y);
        left_diag.insert(y - x);
        right_diag.insert(x + y);
    }

    vector<bool> result(queries.size(), true);
    for( int i = 0 ; i < queries.size(); ++i ){
        int x = queries[i][0], y = queries[i][1];
        if(!found(row, x) && !found(col, y) && 
           !found(left_diag, y - x) && !found(right_diag, x + y ))
           result[i] = false;
    }
    return result;

}  
