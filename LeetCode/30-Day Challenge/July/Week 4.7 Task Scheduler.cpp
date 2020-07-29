/*******************************************
 ***Problema: Task Scheduler
 ***ID: Week4.7
 ***Juez: LeetCode
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26);
        int maxi = 0;
        for( char task: tasks){
            cnt[task - 'A']++;
            maxi = max( maxi, cnt[ task - 'A']);
        }
        
        int rep = -1;
        for(int val:cnt ){
            if( maxi == val )
                rep++;
        }
        
        int res = n * (maxi - 1) + maxi + rep;
        return max(res, (int)tasks.size());
    }
};
