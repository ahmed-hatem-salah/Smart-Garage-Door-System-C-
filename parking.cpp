#include <iostream>
using namespace std;

int getRate(int type) {
    if (type == 1) return 10;    // Car
    if (type == 2) return 5;     // Bike
    if (type == 3) return 15;    // Truck
    return 0;
}

bool isValidTime(int h, int m) {
    return h >= 0 && h < 24 && m >= 0 && m < 60; //btl3 0 2ao 1 fa 2shl mn if()
}

int parkVehicle() {
    string plate; //7rof we 2arkam
    int type, in_hour, in_min, out_hour, out_min; 

    cout << "\n\n what is the Vehicle number: ";
    cin >> plate;

    cout << " \n Vehicle type (1-Car, 2-Bike, 3-Truck): ";
    cin >> type;
    int rate = getRate(type);

    if (rate == 0) { 
        cout << "Invalid type.\n"; return 0 ; 
    }

    char c;
    cout << "Entry time (Hour:Minute): ";

    cin >> in_hour >> c >> in_min;

    cout << "Exit time (Hour:Minute): ";
    cin >> out_hour >> c >> out_min;
    if (!isValidTime(in_hour, in_min) || !isValidTime(out_hour, out_min)) {
        cout << "Invalid time format.\n";
        return 0;
    }

    double in_minTotal = in_hour * 60 + in_min ;

    double out_minTotal = out_hour * 60 + out_min;

    int dur = out_minTotal - in_minTotal;

    if (dur < 0) dur += 24 * 60;

    int blocks = (dur) / 30; //+29
    int fee = blocks * rate;


    cout << "Fee for " << plate << "is " << fee << " EGP\n\n";
    return fee ;
}


int main() {
    int mode;
    cout << "\n===== Parking System =====\n";
    cout << "1 - One vehicle\n2 - Multiple vehicles\nChoose mode: ";
    cin >> mode;

    if (mode == 1) {
        int fee = parkVehicle();
    } 
    else if (mode == 2) {
        int num;
        cout << "How many vehicles do you want to enter? ";
        cin >> num;

        int totalFee = 0;

        for (int i = 0; i < num; ++i) {
           
            int fee = parkVehicle();
            
            totalFee += fee;
        }

        cout << "\nTotal fees for all vehicles: " << totalFee << " EGP\n";
    } 
    else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
