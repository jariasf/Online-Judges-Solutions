/*******************************************
 ***Problema: Strobogrammatic Number II
 ***ID: 776
 ***Juez: LintCode
 ***Tipo: Recursion
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param n: the length of strobogrammatic number
     * @return: All strobogrammatic numbers
     */
    vector<string> possible = {"0", "1", "6", "8", "9"};
    vector<string> result;
    void generateStrobogrammatic(int pos, int n, string num){
        int mid = n/2;
        if(pos == mid){
            int sz = num.size();
            string right = "";
            for( int i = sz - 1 ; i >= 0 ; --i ){
                if( num[i] == '6') right += "9";
                else if( num[i] == '9') right += "6";
                else right += num[i];
            }
            if(n & 1){
                result.push_back(num + "0" + right);
                result.push_back(num + "1" + right);
                result.push_back(num + "8" + right);                                
            }else{
                result.push_back(num + right);
            }
            return;
        }

        int start = 0;
        if( pos == 0 ) start = 1;
        for( int i = start ; i < possible.size(); ++i ){   
            generateStrobogrammatic(pos + 1, n, num + possible[i]);
        }
    }

    vector<string> findStrobogrammatic(int n) {
        result.clear();
        generateStrobogrammatic(0, n, "");
        return result;
    }
};


//sol2
class Solution {
public:
    /**
     * @param n: the length of strobogrammatic number
     * @return: All strobogrammatic numbers
     */
    int N;
    vector<string> generate(int n){
        vector<string> res;
        if( n == 1 ){
            res.push_back("0");
            res.push_back("1");
            res.push_back("8");
            return res;
        }

        if( n == 0 )
            return {""};

        vector<string> tmp = generate(n - 2);
        for(string s: tmp){
            if( n < N - 1)
                res.push_back("0" + s + "0");
            res.push_back("1" + s + "1");
            res.push_back("6" + s + "9");
            res.push_back("8" + s + "8"); 
            res.push_back("9" + s + "6");            
        }
        return res;
    }

    vector<string> findStrobogrammatic(int n) {
        N = n;
        return generate(n);
    }
};

