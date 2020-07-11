/*******************************************
 ***Problema: Reformat Date
 ***ID: 1507
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<string> month = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    string reformatDate(string date) {
        stringstream ss(date);
        string d, m, y;
        ss>>d>>m>>y;
        
        if( isdigit(d[1])){
            d = d.substr(0, 2);
        }else{
            d = "0" + d.substr(0, 1);
        }
        
        int mm = 1;
        for( int i = 0 ; i < month.size(); ++i ){
            if( month[i] == m ){
                mm = i + 1;
                break;
            }
        }
        
        m = to_string(mm);
        if(m.size() == 1 ) m = "0" + m;
        
        return y + "-" + m + "-" + d;
        
    }
};
