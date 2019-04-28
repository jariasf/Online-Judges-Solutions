/*********************************************
 ***Problema: Moving Stones Until Consecutive
 ***ID: 1033
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *********************************************/

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> aux(3);
        aux[0] = a; aux[1] = b; aux[2] = c;
        sort(aux.begin(), aux.end());

        vector<int> res(2);
        a = aux[0]; b = aux[1]; c = aux[2];

        int mini = 0;
        if( a + 1 < b ) mini++;
        if( b + 1 < c ) mini++;
        if( b - a == 2 || c - b == 2 )
            mini = min(mini, 1);

        res[0] = mini;
        res[1] += b - a - 1;
        res[1] += c - b - 1;

        return res;
    }
};
