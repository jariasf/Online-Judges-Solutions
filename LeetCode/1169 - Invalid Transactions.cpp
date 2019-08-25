/*******************************************
 ***Problema: Invalid Transactions
 ***ID: 1169
 ***Juez: LeetCode
 ***Tipo: Brute Force | Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    struct Data{
        string name, city, str;
        int time, amount;
        Data(string n, int t, int a, string c, string s) : name(n), time(t), amount(a), city(c), str(s){}
        Data(){}

        bool operator<( const Data &d ) const{
            return time < d.time;
        }

    };
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        string name, city;
        int time, amount;
        vector<string> res;
        unordered_map<string, vector<Data> > hash;

        for( int i = 0 ; i < n ; ++i ){
            string s = transactions[i];
            for( int j = 0 ; j < s.size(); ++j ) if( s[j] == ',' ) s[j] = ' ';
            stringstream ss(s);
            ss>>name>>time>>amount>>city;
            hash[name].push_back(Data(name,time,amount,city, transactions[i]));
        }

        for( auto it: hash){
            string name = it.first;
            vector<Data> v = it.second;
            sort(v.begin(), v.end() );
            vector<bool> seen(v.size(), 0);
            if( v[0].amount > 1000 ){
                res.push_back(v[0].str);
                seen[0] = 1;
            }
            for( int i = 1 ; i < v.size(); ++i ){
                if( v[i].amount > 1000 ){
                    res.push_back(v[i].str);
                    seen[i] = 1;
                }
                for( int j = i - 1 ; j >= 0 ; --j ){
                    if( v[i].time - v[j].time <= 60 && v[i].city != v[j].city ){
                        if( !seen[i] ){
                            res.push_back(v[i].str);
                            seen[i] = 1;
                        }
                        if( !seen[j]){
                            res.push_back(v[j].str);
                            seen[j] = 1;
                        }
                    }
                    if( v[i].time - v[j].time > 60 ) break;
                }
            }
        }
        return res;
    }
};
