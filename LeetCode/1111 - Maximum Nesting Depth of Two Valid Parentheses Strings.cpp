/*******************************************
 ***Problema: Maximum Nesting Depth of Two Valid Parentheses Strings
 ***ID: 1111
 ***Juez: LeetCode
 ***Tipo: Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define pii pair<int,int>
#define mp make_pair

class Solution {
public:
    
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        stack<pii> S;
        vector<int> depth(n);
        for( int i = 0 ; i < n ; ++i ){
            if( seq[i] == '('){
                S.push(mp(i, 0));
            }else{
                pii index = S.top(); S.pop();
                int cur = index.second;
                depth[i] = depth[ index.first] = cur + 1;
                if( !S.empty() ) S.top().second = max( S.top().second, cur + 1);
            }
        }

        vector<int> res(n);
        int cur = depth[0];
        int mid = cur/2;
        for( int i = 1 ; i < n ; ++i ){
            if( depth[i] == cur ){
                if( i + 1 < n ){
                    cur = depth[i + 1];
                    mid = cur/2;
                    i++;
                    continue;
                }
            }
            
            if( depth[i] <= mid ){
                res[i] = 1;
            }
        }
        
        return res;
    }
};
