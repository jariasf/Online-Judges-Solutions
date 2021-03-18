/*******************************************
 ***Problema: Sum of first K even-length Palindrome
 ***ID: 744
 ***Juez: LintCode
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param k: Write your code here
     * @return: the sum of first k even-length palindrome numbers
     */
    int sumKEven(int k) {
        long long sum = 0;
        for( int i = 1 ; i <= k ; ++i ){
            long long x = i, num = i;
            while(x > 0){
                num = num * 10 + x % 10;
                x /= 10;
            }
            sum += num;
        }
        return sum;
    }
};
