/*******************************************
 ***Problema: Circular Permutation in Binary Representation
 ***ID: 1238
 ***Juez: LeetCode
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int len = 0, total = (1<<n), current = start;
        vector<int> res(total);
        vector<bool> seen(total, false);
        seen[start] = true;
        res[len++] = start;
        while(len < total ){
            for( int i = 0 ; i < n ; ++i ){
                int next = current ^ (1<<i);
                if( !seen[next] ){
                    seen[next] = true;
                    current = next;
                    res[len++] = next;
                    break;
                }
            }
        }
        return res;
    }
};
