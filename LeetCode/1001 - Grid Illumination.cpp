/*******************************************
 ***Problema: Grid Illumination
 ***ID: 1001
 ***Juez: LeetCode
 ***Tipo: Data Structures, Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> row, col, d_left, d_right;
        unordered_set<long long > lamp;
        long long val;
        for( int i = 0 ; i < lamps.size(); ++i ){
            int x = lamps[i][0], y = lamps[i][1];
            row[x]++;
            col[y]++;
            d_left[y - x]++;
            d_right[ N - y - x]++;
            val = x * (long long)N + y;
            lamp.insert(val);
        }
        int n = queries.size();
        vector<int> result(n, 0);
        for( int i = 0 ; i < n ; ++i ){
            int x = queries[i][0], y = queries[i][1];
            if( row[x] > 0 || col[y] > 0 || d_left[y - x] > 0 || d_right[ N - y - x] > 0 ){
                result[i] = 1;
                for( int ii = -1; ii <= 1 ; ++ii ){
                    for( int jj = -1; jj <= 1 ; ++jj ){
                        int nx = ii + x, ny = jj + y;
                        if( nx >= 0 && ny >= 0 && nx < N && ny < N ){
                            long long val = nx * (long long)N + ny;
                            if( lamp.find(val) != lamp.end() ){
                                //turn off
                                row[nx]--;
                                col[ny]--;
                                d_left[ny - nx]--;
                                d_right[N - ny - nx]--;
                                lamp.erase(val);
                            }                        
                        }
                    }
                }
            }
        }
        return result;
    }
};
