/*******************************************
 ***Problema: Mirror Reflection
 ***ID: 858
 ***Juez: LeetCode
 ***Tipo: Math, GCD, LCM
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int GCD(int p, int q){
        if( q == 0 ){
            return p;
        }
        return GCD(q, p % q);
    } 
     
    int LCM(int p, int q){
        return (p * q) / GCD(p,q);
    } 
     
    int mirrorReflection(int p, int q) {
        int lcm = LCM(p, q);
        
        int k = lcm/p;
        
        int r = lcm/q;
        
        if( k & 1 ){
            if( r & 1 ){
                return 1;
            }else{
                return 2;
            }
        }else{
            if( r & 1 ){
                return 0;
            }else{
                return -1;
            }
        }
        
    }
};
