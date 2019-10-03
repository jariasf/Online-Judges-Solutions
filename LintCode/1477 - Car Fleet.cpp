/*******************************************
 ***Problema: Car Fleet
 ***ID: 1477
 ***Juez: LintCode
 ***Tipo: Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param target: the target
     * @param position: the initial position
     * @param speed: the speed
     * @return: How many car fleets will arrive at the destination
     */
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        int n = position.size();
        if( n == 0 ) return 0;
        vector<pair<int,double> > cars;
        for( int i = 0 ; i < n ; ++i )
            cars.push_back( make_pair(position[i], (target - position[i])/(1.0 * speed[i]) ) );
            
        sort(cars.begin(), cars.end());
        int fleet = 1;
        double last_steps = cars[n - 1].second;
        for( int i = n - 2 ; i >= 0 ; --i ){        
            double current_steps = cars[i].second;
            if( current_steps > last_steps ){
                fleet++;
                last_steps = current_steps;
            }
        }
        return fleet;
    }
    
};
