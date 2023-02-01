/*******************************************
 ***Problema: Greatest Common Divisor of Strings
 ***ID: Week 1.1
 ***Juez: LeetCode
 ***Tipo: Brute force | GCD
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Solution 1 – O(max(n1+n2,log(n1*n2)))
class Solution {
public:

    string gcdOfStrings(string str1, string str2) {
        if( str1 + str2 != str2 + str1 ) return "";
        int n1 = str1.size(), n2 = str2.size();        
        return str1.substr(0, gcd(n1,n2));
    }    
};


// Solution 2 – O(min(n1,n2)*(m+n))
class Solution {
public:

    bool divides(string &prefix, int n2, string &s, int n1){
        if(n1 % n2 != 0) return false;
        for(int j = 0, k = 0 ; j < n1 ; ++j, k = (k + 1) % n2 ){
            if( prefix[k] != s[j])
                return false;
        }
        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size(), n = min(n1,n2);
        int largest_idx = 0;
        for(int i = n ; i > 0 ; --i){
            if( divides(str1, i, str1, n1) && divides(str1, i, str2, n2)){
                largest_idx = i;
                break;
            }            
        }
        return str1.substr(0, largest_idx);
    }  
};
