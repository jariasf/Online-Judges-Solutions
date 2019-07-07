/*******************************************
 ***Problema: Corporate Flight Bookings
 ***ID: 1109
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define MAX 20005
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int N) {
        int sz = bookings.size();
        
        vector<int> change(N + 1), sum(N);
        for( int i = 0 ; i < sz ; ++i ){
            int u = bookings[i][0] - 1, v = bookings[i][1] - 1;
            change[u] += bookings[i][2];
            change[v + 1] -= bookings[i][2];
        }
        
        int aux = 0;
        for( int i = 0 ; i < N ; ++i ){
            aux += change[i];
            sum[i] = aux;
        }
        
        return sum;
    }
};
