/*******************************************
 ***Problem: Design Underground System
 ***ID: 1396
 ***Judge: LeetCode
 ***Type: Hashing
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class UndergroundSystem {
public:
    #define pii pair<int,int>
    #define psi pair<string,int>    
    #define mp make_pair
    unordered_map<string, unordered_map<string, pii> > hash;
    unordered_map<int, psi> in;
    UndergroundSystem() {
        in.clear();
        hash.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id] = mp(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        psi cur = in[id];
        string ini = cur.first;
        int t_ini = cur.second;
        
        pii p = mp(0, 0);
        if( hash.find(ini) != hash.end() && hash[ini].find(stationName) != hash[ini].end() ){
            p = hash[ini][stationName];
        }
        
        p.first += (t - t_ini);
        p.second++;
        
        hash[ini][stationName] = p;
    }
    
    double getAverageTime(string startStation, string endStation) {
        pii cur = hash[startStation][endStation];
        return cur.first / (1.0 * cur.second);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
