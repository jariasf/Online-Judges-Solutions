/*******************************************
 ***Problema: Distribute Candies to People
 ***ID: 1103
 ***Juez: LeetCode
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res( num_people );
        for( int i = 0, cnt = 1 ; i < num_people && candies > 0; i = (i + 1) % num_people, cnt++ ){
            int mini = min(cnt, candies);
            res[i] += mini;
            candies -= mini;
        }
        return res;
    }
};
