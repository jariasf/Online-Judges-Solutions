/*****************************************************
 ***Problema: Maximize Sum Of Array After K Negations
 ***ID: 1005
 ***Juez: LeetCode
 ***Tipo: Data Structures - Priority Queue
 ***Autor: Jhosimar George Arias Figueroa
 *****************************************************/

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int n = A.size();
        priority_queue<int, vector<int>, greater<int> > Q;
        for( int i = 0 ; i < n ; ++i ) Q.push(A[i]);
        while(K--){
            int cur = Q.top(); Q.pop();
            cur *= -1;
            Q.push(cur);
        }
        int result = 0;
        while( !Q.empty() ){
            result += Q.top(); Q.pop();
        }
        return result;
    }
};
