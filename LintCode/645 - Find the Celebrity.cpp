/*******************************************
 ***Problema: Find the Celebrity
 ***ID: 645
 ***Juez: LintCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    /**
     * @param n a party with n people
     * @return the celebrity's label or -1
     */
    int findCelebrity(int n) {
        int candidate = 0;
        for( int i = 1 ; i < n ; ++i ){
            if( knows(candidate, i) ){
                candidate = i;
            }
        }
        
        for( int i = 0 ; i < n ; ++i )
            if( candidate != i && (knows(candidate, i) || !knows(i, candidate)) ) 
				return -1;

        return candidate;
    }
};

