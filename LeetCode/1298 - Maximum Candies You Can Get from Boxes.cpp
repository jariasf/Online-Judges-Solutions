/*******************************************
 ***Problema: Maximum Candies You Can Get from Boxes
 ***ID: 1298
 ***Juez: LeetCode
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define mp make_pair
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        unordered_set<int> locked;
        int total = 0;
        queue<int> Q;

        for( int i = 0 ; i < initialBoxes.size(); ++i ){
            int box = initialBoxes[i];
            if( status[box] == 1 ){
                Q.push(box);
            }else{
                locked.insert(box);
            }
        }
        
        while( !Q.empty() ){
            int cur = Q.front(); Q.pop();
            total += candies[cur];
            for( int i = 0 ; i < keys[cur].size(); ++i ){
                status[keys[cur][i]] = 1;
                if( locked.find(keys[cur][i]) != locked.end()){
                    locked.erase(keys[cur][i]);
                    Q.push(keys[cur][i]);
                }
            }

            for( int i = 0 ; i < containedBoxes[cur].size(); ++i ){
                int next = containedBoxes[cur][i];
                if( status[next] == 1 ){
                    Q.push(next);
                }else{
                    locked.insert(next);
                }
            }               
        } 
        return total;
    }
};
