/*******************************************
 ***Problema: Minimum Number of Arrows to Burst Balloons
 ***ID: Week 1.5
 ***Juez: LeetCode
 ***Tipo: Greedy - Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), 
             [](vector<int> &v1, vector<int>&v2){return v1[1]<v2[1];});
        int res = 1;
        int n = points.size();
        int last = points[0][1];
        for(int i = 1 ; i < n ; ++i){
            if(points[i][0] > last){
                res++;
                last = points[i][1];
            }
        }
        return res;
    }
};
