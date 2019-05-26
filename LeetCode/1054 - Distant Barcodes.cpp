/*******************************************
 ***Problema: Distant Barcodes
 ***ID: 1054
 ***Juez: LeetCode
 ***Tipo: Priority Queue
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& v) {
        priority_queue<pair<int,int> > Q;
        
        unordered_map<int,int> hash;
        for( int i = 0 ; i < v.size(); ++i ){
            hash[ v[i] ]++;
        }
        
        for( auto it:hash ){
            Q.push(make_pair(it.second, it.first) );
        }
        
        vector<int> result;
        pair<int,int> prev = make_pair(-1, -1);
        while( !Q.empty() ){
            pair<int,int > p = Q.top();
            Q.pop();
            p.first--;
            result.push_back(p.second);
            if( prev.first > 0 ){
                Q.push(prev);
            }
            prev = p;
        }

        return result;
    }
};
