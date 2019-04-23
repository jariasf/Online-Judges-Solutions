/*******************************************
 ***Problema: Matrix Cells in Distance Order
 ***ID: 1030
 ***Juez: LeetCode
 ***Tipo: Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define pii pair<int,int>
#define mp make_pair
#define pb push_back

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {

        vector<vector<int> > res(R * C, vector<int>(2));
        vector< pair<int, pii> > v;
        for( int i = 0 ; i < R ; ++i ){
            for( int j = 0 ; j < C; ++j ){
                v.push_back( mp( abs(i - r0) + abs(j - c0), mp(i, j)));
            }
        }

        sort(v.begin(), v.end() );

        for( int i = 0 ; i < v.size(); ++i ){
            res[i][0] = v[i].second.first;
            res[i][1] = v[i].second.second;
        }
        return res;
    }
};
