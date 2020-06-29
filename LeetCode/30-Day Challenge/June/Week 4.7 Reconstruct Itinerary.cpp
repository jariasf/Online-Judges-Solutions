/*******************************************
 ***Problema: Reconstruct Itinerary
 ***ID: Week4.7
 ***Juez: LeetCode
 ***Tipo: Euclerian Walk
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    unordered_map<string, vector<string> > adj;
    vector<string> res;
    void tour(string x){
        while ( adj[x].size() > 0) {
            string y = adj[ x ].back();
            adj[x].pop_back();
            tour( y );
            res.push_back( y );
        }
    }    
    
    //[["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        adj.clear();
        for( int i = 0 ; i < tickets.size(); ++i )
            adj[ tickets[i][0] ].push_back(tickets[i][1]);
        
        res.clear();
        
        for( auto &it: adj ){
            sort( it.second.begin(), it.second.end() );
            reverse(it.second.begin(), it.second.end());
        }

        tour("JFK");
        res.push_back("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};
