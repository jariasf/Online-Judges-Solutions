/*******************************************
 ***Problema: Number of Ships in a Rectangle
 ***ID: 1274
 ***Juez: LeetCode
 ***Tipo: Binary Search | QuadTree search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */
class Solution {
public:
    int countShips(Sea sea, vector<int> t, vector<int> b) {
        if(!sea.hasShips(t, b))
            return 0;
        int tx = t[0], ty = t[1];
        int bx = b[0], by = b[1];
        
        if( tx == bx && ty == by ) 
            return 1;
        else{
            int total;
            if( bx < tx ){
                int mx = (tx + bx)/2;
                total = countShips(sea, {mx, ty}, {bx, by}) + countShips(sea, {tx,ty}, {mx + 1, by});
            }else if( by < ty ){
                int my = (ty + by)/2;
                total = countShips(sea, {tx, ty}, {bx, my + 1}) + countShips(sea, {tx,my}, {bx, by});            
            }
            return total;
        }
        
    }
};
