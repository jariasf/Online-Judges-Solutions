/*******************************************
 ***Problema: Number of Students Doing Homework at a Given Time
 ***ID: 1450
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size(), cnt = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( queryTime >= startTime[i] && queryTime <= endTime[i]) cnt++;
        }
        return cnt;
    }
};
