/*******************************************
 ***Problema: Minimize Max Distance to Gas Station
 ***ID: 848
 ***Juez: LintCode
 ***Tipo: Binary Search The Answer
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param stations: an integer array
     * @param k: an integer
     * @return: the smallest possible value of D
     */
    double EPS = 1e-6;
    bool possible(vector<int> &stations, int k, double mid){
        int n = stations.size();
        for( int i = 0 ; i < n - 1 ; ++i ){
            double dif = abs(stations[i + 1] - stations[i]);
            int req = floor(dif/mid);
            if( k >= req ){
                k -= req;
            }else
                return false;
        }
        return k >= 0;
    }
    
    
    double minmaxGasDist(vector<int> &stations, int k) {
        
        int n = stations.size();
        int maxi = 0;
        for( int i = 0 ; i < n - 1 ; ++i )
            maxi = max( maxi, stations[i + 1] - stations[i]);
        
        double left = 0.0, right = maxi + 1, mid;
        while( fabs(left - right) > EPS ){
            mid = (left + right)/2.0;
            if( possible(stations, k, mid) ){
                right = mid;
            }else{
                left = mid;
            }
        }
        return right;
    }
};
