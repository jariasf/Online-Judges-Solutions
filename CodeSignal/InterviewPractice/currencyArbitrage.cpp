/*******************************************
 ***Problem: Currency Arbitrage
 ***Judge: CodeSignal
 ***Type: Floyd-Warshall
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

void floyd(vector<vector<double> > &adj){
    int V = adj.size();
    for(int k = 0 ; k < V ; ++k ){
        for(int i = 0 ; i < V ; ++i ){
            for(int j = 0 ; j < V ; ++j ){
                double t = adj[ i ][ k ] * adj[ k ][ j ];
                if( t > adj[ i ][ j ] ){
                    adj[ i ][ j ] = t;
                }
            }
        }
    }
}

bool currencyArbitrage(std::vector<std::vector<double>> exchange) { 
    floyd(exchange);
    int V = exchange.size();
    for( int i = 0; i < V ; ++i )
        if( exchange[i][i] > 1.0 ) 
            return true;
    
    return false;
}
