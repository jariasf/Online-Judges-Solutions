/*******************************************
 ***Problema: Subrectangle Queries
 ***ID: 1476
 ***Juez: LeetCode
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class SubrectangleQueries {
public:
    vector<vector<int> > v;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        v = rectangle;
    }
    
    void updateSubrectangle(int r1, int c1, int r2, int c2, int val) {
        for( int i = r1 ; i <= r2 ; ++i ){
            for( int j = c1 ; j <= c2; ++j ){
                v[i][j] = val;
            }
        }
    }
    
    int getValue(int row, int col) {
        return v[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
