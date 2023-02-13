/*******************************************
 ***Problema: Count Odd Numbers in an Interval Range
 ***ID: Week 2.6
 ***Juez: LeetCode
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int countOdds(int low, int high) {
        if(!(low & 1)) low++;
        if(!(high & 1)) high--;
        return (high - low + 2)/2; 
    }
};
