/*******************************************
 ***Problema: Strange Sort
 ***ID: 1606
 ***Juez: LintCode
 ***Tipo: Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param n: Length of the array
     * @param num: num array
     * @param cost: cost array
     * @return: nothing
     */
    vector<int> strangeSort(int n, vector<int> &num, vector<int> &cost) {
        vector<pair<int,int> > array;
        for( int i = 0 ; i < n ; ++i)
            array.push_back( make_pair(cost[i], num[i]) );
        sort( array.begin(), array.end());
        vector<int> res(n);
        for( int i = 0 ; i < n ; ++i )
            res[i] = array[i].second;
        return res;
    }
};
