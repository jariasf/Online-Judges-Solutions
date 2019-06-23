/*******************************************
 ***Problema: Car Pooling
 ***ID: 1094
 ***Juez: LeetCode
 ***Tipo: Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define pii pair<int,int>
#define mp make_pair
class Solution {
public:   
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<pii> info;
        for( int i = 0 ; i <  n ; ++i ){
            info.push_back( mp(trips[i][1], (i + 1)  ) );
            info.push_back( mp(trips[i][2], -(i + 1 ) ) );
        }
        sort( info.begin(), info.end() );
        for( int i = 0 ; i < info.size(); ++i ){
            if( info[i].second > 0 ){
                capacity -= trips[ info[i].second - 1][0];
                if( capacity < 0 ) return false;
            }else{
                capacity += trips[-info[i].second - 1][0];
            }
        }
        return true;
    }
};
