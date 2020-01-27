/*******************************************
 ***Problema: Filter Restaurants by Vegan-Friendly, Price and Distance
 ***ID: 1333
 ***Juez: LeetCode
 ***Tipo: Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    #define pii pair<int,int>
    #define mp make_pair
    vector<int> filterRestaurants(vector<vector<int>>& r, int vegan, int maxPrice, int maxDist) {
        int n = r.size();
        vector<pii> v;
        //restaurants[i] = [idi, ratingi, veganFriendlyi, pricei, distancei]
        for( int i = 0 ; i < n ; ++i ){
            int price = r[i][3];
            int dist = r[i][4];
            if( price <= maxPrice && dist <= maxDist ){
                if( r[i][2] >= vegan ){
                    v.push_back( mp(r[i][1], r[i][0]) );    
                }
            }
        }
        
        sort(v.rbegin(), v.rend() );
        vector<int> res(v.size());
        for( int i = 0 ; i < v.size(); ++i ){
            res[i] = v[i].second;
        }
        return res;
    }
};
