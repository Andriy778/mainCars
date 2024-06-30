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

class Truck : public Car {
public:
    Truck(const string& br, const string& mo, int yr, double cost)
        : Car(br, mo, yr, cost) {}

    void displayType() const override {
        cout << "This is a truck." << endl;
    }

    void displayDetails() const override {
        cout << "Truck - ";
        Car::displayDetails();
    }

    double maintenanceCost() const override {
        return baseCost * 1.8;
    }
};

class Garage {
private:
    vector<Car*> cars;

public:
    ~Garage() {
        for (auto& car : cars) {
            delete car;
        }
    }

    void addCar(Car* car) {
        cars.push_back(car);
    }

    void removeCar(int index) {
        if (index >= 0 && index < cars.size()) {
            delete cars[index];
            cars.erase(cars.begin() + index);
        } else {
            cout << "Invalid index!" << endl;
        }
    }

    void displayAllCars() const {
        for (const auto& car : cars) {
            car->displayDetails();
        }
    }

    void displayMaintenanceCosts() const {
        for (const auto& car : cars) {
            car->displayDetails();
            cout << "Maintenance Cost: $" << car->maintenanceCost() << endl;
        }
    }

    void displayCarTypes() const {
        for (const auto& car : cars) {
            car->displayType();
        }
    }
};

int main() {
    return 0;
}
