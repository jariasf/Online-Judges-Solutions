/*******************************************
 ***Problema: Jump Game III
 ***ID: 1306
 ***Juez: LeetCode
 ***Tipo: BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> seen(n);
        queue<int> Q;
        Q.push(start);
        seen[start] = 1;
        while( !Q.empty() ){
            int cur = Q.front(); Q.pop();
            if( arr[cur] == 0 ) return true;
            if( cur + arr[cur] < n && !seen[ cur + arr[cur] ] ){
                seen[ cur + arr[cur] ] = 1;
                if( arr[cur + arr[cur]] == 0 ) return true;
                Q.push(cur + arr[cur] );
            }
            
            if( cur - arr[cur] >= 0 && !seen[ cur - arr[cur] ] ){
                seen[ cur - arr[cur] ] = 1;
                if( arr[cur - arr[cur]] == 0 ) return true;                
                Q.push(cur - arr[cur] );
            }
        }
        return false;
    }
};
