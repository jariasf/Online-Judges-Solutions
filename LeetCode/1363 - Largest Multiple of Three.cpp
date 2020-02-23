/*******************************************
 ***Problem: Largest Multiple of Three
 ***ID: 1363
 ***Judge: LeetCode
 ***Type: Queue + Sorting
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    queue<int> Q[4];
    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(), digits.end());
        int n = digits.size();
        int sum = 0;

        for( int i = 0 ; i < n ; ++i ){
            sum += digits[i];
            Q[digits[i] % 3].push(digits[i]);
        }
        
        if( sum % 3 == 1 ){
            if( !Q[1].empty() ) Q[1].pop();
            else{
                if( !Q[2].empty() ) Q[2].pop();
                else return "";
                if( !Q[2].empty() ) Q[2].pop();
                else return "";
            }
        }else if( sum % 3 == 2 ){
            if( !Q[2].empty() ) Q[2].pop();
            else{
                if( !Q[1].empty() ) Q[1].pop();
                else return "";
                if( !Q[1].empty() ) Q[1].pop();
                else return "";
            }
        }

        string res = "";
        for( int i = 0 ; i < 3 ; ++i ){
            while( !Q[i].empty() ){
                res += (char)(Q[i].front() + '0');
                Q[i].pop();
            } 
        }
        sort(res.rbegin(), res.rend());
        if( res[0] == '0') return "0";
        return res;
    }
};
