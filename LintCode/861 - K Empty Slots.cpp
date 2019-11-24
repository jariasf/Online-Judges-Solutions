/*******************************************
 ***Problema: K Empty Slots
 ***ID: 861
 ***Juez: LintCode
 ***Tipo: Two Pointers + Sliding Window
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param flowers: the place where the flower will open in that day
     * @param k:  an integer
     * @return: in which day meet the requirements
     */
    int kEmptySlots(vector<int> &flowers, int k) {
        int n = flowers.size();
        vector<int> pos(n);
        for( int i = 0 ; i < n ; ++i )
            pos[flowers[i]-1] = i;

        int left = 0, right = k + 1, minDay = 1<<30;
        while(right < n){
            int i = left + 1;
            for(; i < right; ++i ){
                if( pos[left] > pos[i] || pos[right] > pos[i] ){
                    break;
                }
            }
            
            if( i == right ){
                minDay = min( minDay, max(pos[left], pos[right]));
            }
            left = i; right = i + k + 1;
        }
        
        if( minDay == 1<<30 ) return -1;
        return minDay + 1;
    }
};
