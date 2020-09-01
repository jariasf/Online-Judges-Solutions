/*******************************************
 ***Problema: Largest Time for Given Digits
 ***ID: Week1.1
 ***Juez: LeetCode
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    vector<int> top = {2, 3, 5, 9};
    string largestTimeFromDigits(vector<int>& A) {
        int maxi = -1;
        vector<int> idx = {0, 1, 2, 3};
        string res = "";
        do{
            int h1 = A[idx[0]], h2 = A[idx[1]];
            int m1 = A[idx[2]], m2 = A[idx[3]];
            if( m1 <= 5 && m2 <= 9 ){
                if( (h1 == 2 && h2 <= 3) || (h1 < 2 && h2 <= 9) ){
                    int val = h1 * 1000 + h2 * 100 + m1 * 10 + m2;
                    if( val > maxi ){
                        maxi = val;
                        res = to_string(h1) + to_string(h2) + ":" + to_string(m1) + to_string(m2);
                    }
                }
            }
        }while(next_permutation(idx.begin(), idx.end()));
        return res;
    }
};
