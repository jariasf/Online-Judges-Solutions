/*******************************************
 ***Problema: Implement Rand10() Using Rand7()
 ***ID: 1496
 ***Juez: LintCode
 ***Tipo: Rejection Sampling
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int max;
        do{
           max = 7 * (rand7() - 1) + rand7() - 1; //values between [0-48]    
        }while( max > 39);
        return max % 10 + 1;
    }
};
