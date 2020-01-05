/*******************************************
 ***Problema: XOR Queries of a Subarray
 ***ID: 1308
 ***Juez: LeetCode
 ***Tipo: Prefix XOR | Segment Tree
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n + 1);
        for( int i = 1 ; i <= n ; ++i )
            prefix[i] = prefix[i - 1] ^ arr[i - 1]; 
        
        int m = queries.size();
        vector<int> res(m);
        
        for( int i = 0 ; i < m; ++i ){
            res[i] = prefix[ queries[i][1] + 1] ^ prefix[ queries[i][0] ];
        }
        return res;
    }
};


// Segment Tree
class Solution {
public:
    #define MAX 100005
    typedef long long LL;
    LL tree[MAX];
    
    vector<int> v;
    void build(int left, int right, int node = 0){
        if(left == right){
            tree[node] = v[left]; 
            return;
        }
        int mid = (left + right)/2;
        build(left, mid, 2 * node + 1);
        build(mid + 1, right, 2 * node + 2);
        tree[node] = tree[2*node + 1] ^ tree[2*node + 2];
    }
    
    LL query(int from, int to, int left, int right, int node=0){
        if( left >= from && right <= to ){
            return tree[ node ];
        }
        
        int mid = ( left + right )/2;
        LL res = 0;
        if( from <= mid ){
            res = res ^ query( from , to , left , mid , node * 2 + 1 );
        }
        if( to > mid ){
            res = res ^ query( from , to , mid + 1 , right , 2 * node + 2 );
        }
        return res;
    }
    
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        v = arr;
        build(0, n-1);
        vector<int> res(queries.size());
        for( int i = 0 ; i < queries.size(); ++i ){
            res[i] = query(queries[i][0], queries[i][1], 0, n -1);
        }
        return res;
    }
};
