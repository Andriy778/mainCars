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

// Derived class Sedan
class Sedan : public Car {
public:
    Sedan(const string& br, const string& mo, int yr, double cost)
        : Car(br, mo, yr, cost) {}

    void displayType() const override {
        cout << "This is a sedan." << endl;
    }

    void displayDetails() const override {
        cout << "Sedan - ";
        Car::displayDetails();
    }

    double maintenanceCost() const override {
        return baseCost * 1.2;
    }
};

class SUV : public Car {
public:
    SUV(const string& br, const string& mo, int yr, double cost)
        : Car(br, mo, yr, cost) {}

    void displayType() const override {
        cout << "This is an SUV." << endl;
    }

    void displayDetails() const override {
        cout << "SUV - ";
        Car::displayDetails();
    }

    double maintenanceCost() const override {
        return baseCost * 1.5;
    }
};


int main() {
    return 0;
}
