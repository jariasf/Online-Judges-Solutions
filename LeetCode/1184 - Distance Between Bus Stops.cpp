/*******************************************
 ***Problema: Distance Between Bus Stops
 ***ID: 1184
 ***Juez: LeetCode
 ***Tipo: Ad hoc, Simulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        if( start == destination ) return 0;
        int right = 0, left = 0, tot = 0;
        for( int i = start ; i != destination ; i = (i + 1) %n )
            right += distance[i];
        
        for( int i = 0 ; i< n ; ++i )            
            tot += distance[i];

        return min(right , tot - right);
    }
};
