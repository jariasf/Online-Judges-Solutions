/*******************************************
 ***Problem: Number of Steps to Reduce a Number in Binary Representation to One
 ***ID: 1404
 ***Judge: LeetCode
 ***Type: Ad hoc
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int numSteps(string s) {
        int carry = 0, steps = 0;
        while( s != "1" ){
            if( carry + s.back() - '0' == 1 ){ //odd
                steps += 2;
                carry = 1;
            }else{ //even
                steps++;
            }
            s.pop_back();
        }
        return steps + carry;
    }
};



// Simulate the solution
class Solution {
public:
    void increment(bitset<505> &v, int n ){
        int carry = 1;
        for( int i = 0 ; i < n; ++i ){
            if( v[i] == 1 ){
                if( carry == 1 ){
                    v[i] = 0;
                    carry = 1;
                }else break;
            }else{
                v[i] = 1;
                break;
            }
        }
    }
    
    bool check(bitset<505> &v, int n ){
        if( v[0] == 0 ) return false;
        for( int i = 1 ; i < n; ++i ){
            if( v[i] == 1 ) return false;
        }
        return true;
    }
    
    int numSteps(string s) {
        int n = s.size();
        int steps = 0;
        bitset<505> v(s);
        while(!check(v, n + 5)){
            if( v[0] == 1 ){
                increment(v, n+ 5);
            }else{
                v = v>>1;
            }
            steps++;
        } 
        return steps;
    }
};
