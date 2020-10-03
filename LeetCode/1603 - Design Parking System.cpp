/*******************************************
 ***Problema: Design Parking System
 ***ID: 1603
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class ParkingSystem {
public:
    int v[3];
    ParkingSystem(int big, int medium, int small) {
        v[0] = big;
        v[1] = medium;
        v[2] = small;
    }
    
    bool addCar(int carType) {
        carType--;
        if(v[carType]-- > 0)
            return true;
        return false;
    }
};
