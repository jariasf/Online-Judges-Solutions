/*******************************************
 ***Problema: Flight Plan
 ***Juez: CodeSignal
 ***Tipo: Dijkstra
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

struct Data{
    int v, t_depart, t_arrive;
    Data(int _v, int _t_depart, int _t_arrive){
        v = _v;
        t_depart = _t_depart;
        t_arrive = _t_arrive;
    }

    Data(int _v, int _t_arrive){
        v = _v;
        t_arrive = _t_arrive;
    }

    Data(){

    }

    bool operator<(const Data &d)const{
        return t_arrive > d.t_arrive;
    }
};

int convertTimeStr(string &t){
    int h = (t[0] - '0') * 10 + (t[1] - '0');
    int m = (t[3] - '0') * 10 + (t[4] - '0');
    return h * 60 + m;
}

string convertTimeInt(int &t){
    int h = t/60;
    int m = t%60;
    string hh = "", mm = "";
    if( h < 10 ) hh = "0";
    if( m < 10 ) mm = "0";
    hh += to_string(h);
    mm += to_string(m);
    return hh + ":" + mm;
}

vector<vector<Data> > adj;

pair<int,int> create_graph(vector<vector<string> > &times, string source, string dest){
    int V = 0;
    map<string, int> hash;
    hash[source] = hash[dest] = 0;
    for( int i = 0 ; i < times.size(); ++i ){
        string su = times[i][0], sv = times[i][1];
        hash[su] = hash[sv] = 0;
    }

    for( auto &it: hash ){
        it.second = V++;
    }

    adj = vector<vector<Data> >(V + 1); 

    for( int i = 0 ; i < times.size(); ++i ){
        string su = times[i][0], sv = times[i][1];
        int u = hash[su], v = hash[sv];
        adj[u].push_back(Data(v, convertTimeStr(times[i][2]), convertTimeStr(times[i][3])));
    }

    return make_pair(hash[source], hash[dest]);
}

#define INF 1<<30
string dijkstra(int start, int end){
    priority_queue<Data> Q;
    int V = adj.size();

    for( int i = 0 ; i < adj[start].size(); ++i ){
        int v = adj[start][i].v, t_arrive = adj[start][i].t_arrive;
        Q.push(Data(v, t_arrive));
    }

    while(!Q.empty() ){
        Data cur = Q.top(); Q.pop();
        int u = cur.v, t_depart = cur.t_arrive + 60;
        if( u == end ){
            return convertTimeInt(cur.t_arrive);
        }
        for( int i = 0 ; i < adj[u].size(); ++i ){
            int v = adj[u][i].v, tv_depart = adj[u][i].t_depart;
            int tv_arrive = adj[u][i].t_arrive;
            if( tv_depart >= t_depart ){
                Q.push(Data(v, tv_arrive));
            }
        }
    }
    return "-1";
}


std::string flightPlan(std::vector<std::vector<std::string>> times, std::string source, std::string dest) {
    pair<int,int> ids = create_graph(times, source, dest);
    return dijkstra(ids.first, ids.second);
}

