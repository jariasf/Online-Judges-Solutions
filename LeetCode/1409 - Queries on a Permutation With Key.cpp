/*******************************************
 ***Problem: Queries on a Permutation With Key
 ***ID: 1409
 ***Judge: LeetCode
 ***Type: Simulation
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();
        vector<int> res;
        vector<int> p(m);
        for( int i = 0 ; i < m ; ++i ) p[i] = i + 1;

        for( int i = 0 ; i < n ; ++i ){
            int j = 0;
            for( ; j < m ; ++j ){
                if( p[j] == queries[i] ){
                    break;
                }
            }
            res.push_back(j);
            while( j - 1 >= 0 ){
                swap(p[j], p[j - 1]);
                j--;
            }
        }

        return res;
    }
};
