/*******************************************
 ***Problema: Largest Rectangle in Histogram
 ***ID: Week5.3
 ***Juez: LeetCode
 ***Tipo: Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    int largestRectangleArea(vector<int>& A) {
        A.push_back(0);
        int sz = A.size();
        int ans = 0;
        stack< pii > S;
        for( int i = 0 ; i < sz ; ++i ){
             pii last;
             int width = 0;
             while(!S.empty() && S.top().first >= A[i] ){
                last = S.top(); S.pop();
                width += last.second;
                ans = max( ans, last.first * width );
             }
             S.push( mp(A[i], width + 1 ));
        }
        return ans;
    }
};
