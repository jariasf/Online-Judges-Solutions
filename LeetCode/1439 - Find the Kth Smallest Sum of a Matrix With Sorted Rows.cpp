/*******************************************
 ***Problem: Find the Kth Smallest Sum of a Matrix With Sorted Rows
 ***ID: 1439
 ***Judge: LeetCode
 ***Type: Priority Queue
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

// Priority Queue
class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    vector<int> smallestPair(vector<int> &v1, vector<int> &v2, int k){
        priority_queue<pii, vector<pii>, greater<pii> > Q;
        vector<int> res;
        int m = v1.size();
        for( int i = 0 ; i < v2.size() ; ++i )
            Q.push(mp(v1[0] + v2[i], 0));
        
        while(k-- > 0 && !Q.empty()){
            pii cur = Q.top(); Q.pop();
            int a = v1[cur.second], b = cur.first - a;
            res.push_back(cur.first);      
            if( cur.second + 1 < m ) Q.push( mp(v1[cur.second + 1] + b, cur.second + 1));
        }        
        return res;
    }
    
    
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<int> res = mat[0];
        for( int i = 1 ; i < n ; ++i )
            res = smallestPair(res, mat[i], k);
        return res.back();
    }
};


// Sorting + Brute Force
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<int> v;
        for( int j = 0 ; j < m ; ++j ) v.push_back(mat[0][j]);        
        for( int i = 1 ; i < n ; ++i ){
            vector<int> tmp;
            for( int j = 0 ; j < m ; ++j ){
                for( int w = 0 ; w < v.size(); ++w ){
                    tmp.push_back( v[w] + mat[i][j]);
                }
            }
            v = tmp;
            sort( v.begin(), v.end() );
            while( v.size() > k ) v.pop_back();
        }
        return v.back();
    }
};
