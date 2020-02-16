/*******************************************
 ***Problem: Maximum Number of Events That Can Be Attended
 ***ID: 1353
 ***Judge: LeetCode
 ***Type: Priority Queue | Multiset
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    struct cmp{
        bool operator()(vector<int> &v1, vector<int> &v2){
            return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
        }
    }comp;
    
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort( events.begin(), events.end(), comp);
        multiset<int> ms;
        int mini = events[0][0], maxi = 0;
        for( int i = 0 ; i < n ; ++i )
            maxi = max(maxi, events[i][1]);

        int index = 0;
        int total = 0;
        for( int i = mini; i <= maxi ; ++i ){    
            while( index < n && events[index][0] == i ){
                ms.insert(events[index++][1]);
            }
            
            while( !ms.empty() ){
                auto it = ms.begin();
                int end_index = *it;
                ms.erase(it);
                if( end_index < i){
                    continue;
                }
                total++;
                break;
            }
            
        }
        return total;
    }
};
