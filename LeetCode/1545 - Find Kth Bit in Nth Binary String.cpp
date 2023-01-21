/*******************************************
 ***Problema: Find Kth Bit in Nth Binary String
 ***ID: 1545
 ***Juez: LeetCode
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:  
    
    char findKthBit(int n, int k) {
        vector<bool> last, tmp;
        last.push_back(0);        
        while( last.size() < k ){
            tmp = last;           
            last.flip();
            reverse(last.begin(), last.end());
            tmp.push_back(1);
            for( bool b: last )
                tmp.push_back(b);
            last = tmp;
        }
        return (char)(last[k - 1] + '0');
    }
};
