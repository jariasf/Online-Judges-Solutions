/*******************************************
 ***Problema: Minimum Cycle Section
 ***ID: 1365
 ***Juez: LintCode
 ***Tipo: Prefix Function
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param array: an integer array
     * @return: the length of the minimum cycle section
     */
    int minimumCycleSection(vector<int> &array) {
        int n = array.size();
        vector<int> p(n + 1);
        p[0] = -1;
        int i = 1, j = 0;
        while( i < n ){    
            while( j >= 0 && array[i] != array[j]){
                j = p[j];
            }
            i++; j++;
            p[i] = j;
        }
        return n - p[n];
    }
};
