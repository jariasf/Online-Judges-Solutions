/*******************************************
 ***Problema: Smallest Common Region
 ***ID: 1257
 ***Juez: LeetCode
 ***Tipo: Lowest Common Ancestor
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Without Hashing
class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> parent;
        for( int i = 0 ; i < regions.size(); ++i ){
            vector<string> reg = regions[i];
            string root = reg[0];
            for( int j = 1 ; j < reg.size(); ++j ){
                string v = reg[j];
                parent[v] = root;
            }
        }
        queue<string> p1, p2;
        string u = region1, v = region2;
        while( true ){
            p1.push(u);
            if( parent.find(u) == parent.end() ) break;
            u = parent[u];
        }
        
        while(true){
            p2.push(v);
            if( parent.find(v) == parent.end() ) break;            
            v = parent[v];
        }
        
        while( p1.size() > p2.size() ){
            p1.pop();
        }
        
        while( p2.size() > p1.size() ){
            p2.pop();
        }
        
        string result = "";
        while( p1.size() > 0 ){
            u = p1.front(); p1.pop();
            v = p2.front(); p2.pop();
            if( u == v ){
                result = u;
                break;
            }
        }
        return result;
    }
};

// Using Hashing
class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        int V = 0;
        unordered_map<string, int> hash;
        unordered_map<int, string> rev;
        for( int i = 0 ; i < regions.size(); ++i ){
            vector<string> reg = regions[i];
            for( int j = 0 ; j < reg.size(); ++j ){
                if( hash.find(reg[j]) == hash.end() ){
                    hash[reg[j]] = V;
                    rev[V] = reg[j];
                    V++;
                }
            }
        }
        vector<int> parent(V + 5, -1);
        for( int i = 0 ; i < regions.size(); ++i ){
            vector<string> reg = regions[i];
            int root = hash[reg[0]];
            for( int j = 1 ; j < reg.size(); ++j ){
                int v = hash[reg[j]];
                parent[v] = root;
            }
        }
        
        int u = hash[region1], v = hash[region2];
        
        queue<int> p1, p2;
        
        while( u != -1 ){
            p1.push(u);
            u = parent[u];
        }
        
        while(v != -1 ){
            p2.push(v);
            v = parent[v];
        }
        
        while( p1.size() > p2.size() ){
            p1.pop();
        }
        
        while( p2.size() > p1.size() ){
            p2.pop();
        }
        
        string result = "";
        while( p1.size() > 0 ){
            u = p1.front(); p1.pop();
            v = p2.front(); p2.pop();
            if( u == v ){
                result = rev[u];
                break;
            }
        }
        return result;
    }
};
