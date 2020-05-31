/*******************************************
 ***Problema: K Closest Points to Origin
 ***ID: Week5.2
 ***Juez: LeetCode
 ***Tipo: Sorting | Priority Queue
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Priority Queue O(nlogk)
class Solution {
public:
    struct comp {
        bool operator()(vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int> > res;
        priority_queue<vector<int>, vector<vector<int> >, comp > Q;
        for( int i = 0 ; i < K ; ++i )
            Q.push(points[i]);
        
        for( int i = K ; i < points.size(); ++i ){
            Q.push(points[i]);
            Q.pop();
        }
        
        while( !Q.empty() ){
            res.push_back(Q.top());
            Q.pop();
        }
        return res;
    }  
};

// Sorting O(nlogn)
class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int> > res;
        int n = points.size();
        vector<pii> d(n);
        
        for( int i = 0 ; i < n ; ++i ){
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            d[i] = mp( dist, i);
        }
        
        sort(d.begin(), d.end());
        for( int i = 0 ; i < K ; ++i )
            res.push_back(points[d[i].second]);
        return res;
    }
};
