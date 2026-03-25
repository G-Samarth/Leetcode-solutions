class ParkingSystem {
    int big, medium, small;
public:
    ParkingSystem(int big, int medium, int small)
    : big(big), medium(medium), small(small) {}
    
    bool addCar(int carType) {
        if(carType == 1){
            if(!big)
                return false;
            big--;
            return true;
        }
        if(carType == 2){
            if(!medium)
                return false;
            medium--;
            return true;
        }
        if(carType == 3){
            if(!small)
                return false;
            small--;
            return true;
        }

        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */