#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base class Car
class Car {
protected:
    string brand;
    string model;
    int year;
    double baseCost;

public:
    Car(const string& br, const string& mo, int yr, double cost)
        : brand(br), model(mo), year(yr), baseCost(cost) {}

    virtual void displayType() const {
        cout << "This is a generic car." << endl;
    }

    virtual void displayDetails() const {
        cout << "Brand: " << brand << ", Model: " << model << ", Year: " << year << endl;
    }

    virtual double maintenanceCost() const {
        return baseCost * 1.0;
    }

    virtual ~Car() {}
};

int main() {
    return 0;
}
