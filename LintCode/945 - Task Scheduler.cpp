/*******************************************
 ***Problema: Task Scheduler
 ***ID: 945
 ***Juez: LintCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param tasks: the given char array representing tasks CPU need to do
     * @param n: the non-negative cooling interval
     * @return: the least number of intervals the CPU will take to finish all the given tasks
     */
    int leastInterval(string &tasks, int n) {
        int m = tasks.size();
        int result = 0, maximum = 0;
        vector<int> freq(26);
        for( char c : tasks ){
            freq[c - 'A']++;
            maximum = max(maximum, freq[c - 'A']);
        }

        int cnt = 0;
        for( int val: freq ){
            if(val == maximum) cnt++;
        }

        result = maximum + cnt - 1 + n * (maximum - 1);
        return max(result, (int)tasks.size());
    }
};
