/*******************************************
 ***Problema: Meeting Scheduler    
 ***ID: 1229
 ***Juez: LeetCode
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int i, j;
        i = j = 0;
        int sz1 = slots1.size(), sz2 = slots2.size();
        vector<int> res;
        while( i < sz1 && j < sz2 ){
            int max_start = max( slots1[i][0], slots2[j][0]);
            int min_end = min(slots1[i][1], slots2[j][1]);
            if( max_start <= min_end ){
                int time = min_end - max_start;
                if( time >= duration ){
                    res = {max_start, max_start + duration};
                    break;
                }
            }
            if( slots2[j][1] < slots1[i][1] ) j++;
            else i++;
        }
        return res;
    }
};
