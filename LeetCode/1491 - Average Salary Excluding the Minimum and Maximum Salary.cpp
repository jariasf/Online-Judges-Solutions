/*******************************************
 ***Problema: Average Salary Excluding the Minimum and Maximum Salary
 ***ID: 1491
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size(), mini = 1<<30, maxi= 0, res = 0;
        double denom = n - 2;
        for( int i = 0 ; i < salary.size() ; ++i ){
            res += salary[i];
            mini = min(mini, salary[i]);
            maxi = max(maxi, salary[i]);
        }
        return (res - mini - maxi)/denom;
    }
};
