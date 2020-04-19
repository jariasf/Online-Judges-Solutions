/*******************************************
 ***Problem: Display Table of Food Orders in a Restaurant
 ***ID: 1418
 ***Judge: LeetCode
 ***Type: Hashing + Set
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        int n = orders.size();
        vector<vector<string>> res;
        
        unordered_map<string, int> hash[505];
        set<string> names;
        set<int> ids;
        for( int i = 0 ; i < n ; ++i ){
            int id = stoi(orders[i][1]);
            hash[id][orders[i][2]]++;
            names.insert(orders[i][2]);
            ids.insert(id);
        }
        
        vector<string> top;
        top.push_back("Table");
        for(auto s:names )
            top.push_back(s);
        
        res.push_back(top);
        for(auto id: ids){
            vector<string> tmp;
            tmp.push_back(to_string(id));
            for(auto name: names )
                tmp.push_back( to_string(hash[id][name]));
            res.push_back(tmp);
        }
        return res;
        
    }
};
