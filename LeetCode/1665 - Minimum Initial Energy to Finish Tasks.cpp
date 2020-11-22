/*******************************************
 ***Problema: Minimum Initial Energy to Finish Tasks
 ***ID: 1665
 ***Juez: LeetCode
 ***Tipo: Sorting + (Greedy | Binary Search the answer)
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    static bool comp(vector<int> &v1, vector<int> &v2){
        int dif1 = (v1[1] - v1[0]), dif2 = (v2[1] - v2[0]);
        return dif1 < dif2;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), comp);
        int res = 0;
        for( int i = 0 ; i < tasks.size(); ++i ){
            res = max(res + tasks[i][0], tasks[i][1]);
        }
        return res;
    }

};
