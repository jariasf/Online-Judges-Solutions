/*******************************************
 ***Problema: Distribute Candies to People
 ***ID: Week3.3
 ***Juez: LeetCode
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people);
        int n = 1;
        while( (n * (n + 1))/2 <= candies ){
            n++;
        }
        n--;
        int tot = (n * (n + 1))/2, pos = 0;
        for( int i = 1 ; i <= n ; ++i, pos = (pos + 1) % num_people )
            res[pos] += i;
        res[pos] += candies - tot;
        return res;
    }
};
