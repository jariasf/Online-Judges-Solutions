/*******************************************
 ***Problema: Minimum Area Rectangle
 ***ID: 939
 ***Juez: LeetCode
 ***Tipo: Sorting + Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define pii pair<int, vector<int> >
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();
        long long result = 1LL<<60;
        
        map<int, vector<int> > x;
        unordered_map<int, vector<int> > y;
        
        unordered_map<int, unordered_set<int> > hash;
        
        for( int i = 0 ; i < n; ++i ){
            vector<int> p = points[i];
            x[p[0]].push_back(p[1]);
            y[p[1]].push_back(p[0]);
            hash[p[0]].insert(p[1]);
        }
        
        for( auto &it: x){
            sort(it.second.begin(), it.second.end());
        }
        
        
        for( auto &it: y){
            sort(it.second.begin(), it.second.end());
        }
        
        for( auto it: x ){
            vector<int> v = it.second;
            int x1 = it.first;
            for( int i = 0 ; i < v.size(); ++i ){
                int y1 = v[i];
                for( int j = i + 1; j < v.size(); ++j ){
                    int y2 = v[j];
                    int area = y2 - y1;
                    if( area >= result ) break;
                    vector<int> h = y[y2];
                    for( int k = 0 ; k < h.size(); ++k ){
                        int x2 = h[k];
                        if( x2 > x1 ){
                            if( hash[x2].find(y1) != hash[x2].end() ){
                                area = (y2 - y1) * (x2 - x1);
                                if( area < result ){
                                    result = area;
                                }else{
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        
        if( result == 1LL<<60 ) return 0;
        return result;
    }
};
