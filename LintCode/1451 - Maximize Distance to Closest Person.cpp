/*******************************************
 ***Problema: Maximize Distance to Closest Person
 ***ID: 1451
 ***Juez: LintCode
 ***Tipo: Ad hoc - Group By Zero
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param seats: an array
     * @return: the maximum distance
     */
    int maxDistToClosest(vector<int> &seats) {
        int n = seats.size();
        int max_dist = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( seats[i] == 0 ){
                int j = i + 1;
                while(j < n && seats[j] == 0){
                    j++;
                }
                int zeros = j - i, distance;
                if(i == 0 || j == n){
                    distance = zeros;
                }else{
                    if(zeros % 2 == 0 ){
                        distance = zeros/2;
                    }else{
                        distance = (zeros + 1)/2;
                    }
                }
                max_dist = max(max_dist, distance);
                i = j - 1;
            }
        }
        return max_dist;
    }
};
