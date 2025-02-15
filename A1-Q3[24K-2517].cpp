#include <iostream>
#include <string>
using namespace std;

class User
{
private:
    int userID;
    string name;
    int age;
    string licenseType;
    string contact;

public:
    User(int id, string n, int a, string license, string c) : userID(id), name(n), age(a), licenseType(license), contact(c) {}

    int getUserID()
    {
        return userID;
    }
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    string getLicenseType()
    {
        return licenseType;
    }
    string getContact()
    {
        return contact;
    }

    void setName(string n)
    {
        name = n;
    }
    void setAge(int a)
    {
        age = a;
    }
    void setLicenseType(string license)
    {
        licenseType = license;
    }
    void setContact(string c)
    {
        contact = c;
    }
};

class Vehicle
{
private:
    string model;
    double rentalPrice;
    string requiredLicense;

public:
    Vehicle(string m, double price, string license) : model(m), rentalPrice(price), requiredLicense(license) {}

    string getModel()
    {
        return model;
    }
    double getRentalPrice()
    {
        return rentalPrice;
    }
    string getRequiredLicense()
    {
        return requiredLicense;
    }
};

class RentalSystem
{
private:
    Vehicle *vehicles[3];
    int vehicleCount;

public:
    RentalSystem() : vehicleCount(0) {}

    void addVehicle(Vehicle *v)
    {
        if (vehicleCount < 3)
        {
            vehicles[vehicleCount++] = v;
        }
    }

    void showAvailableVehicles()
    {
        for (int i = 0; i < vehicleCount; i++)
        {
            cout << "Model: " << vehicles[i]->getModel() << ", Price: " << vehicles[i]->getRentalPrice() << endl;
        }
    }

    void rentVehicle(User &user, string model)
    {
        for (int i = 0; i < vehicleCount; i++)
        {
            if (vehicles[i]->getModel() == model)
            {
                if (user.getLicenseType() == vehicles[i]->getRequiredLicense())
                {
                    cout << user.getName() << " rented " << model << " successfully!" << endl;
                }
                else
                {
                    cout << "You do not have the required license to rent this vehicle." << endl;
                }
                return;
            }
        }
        cout << "Vehicle not found!" << endl;
    }
};

int main()
{
    cout << "Hasan Waseem, ID : 24K2517" << endl;
    User user1(251, "Hasan", 25, "Full", "123-456");
    Vehicle v1("Tesla", 50, "Full");
    Vehicle v2("Porsche", 30, "Learner");
    RentalSystem rentalSystem;
    rentalSystem.addVehicle(&v1);
    rentalSystem.addVehicle(&v2);

    cout << "Available vehicles:" << endl;
    rentalSystem.showAvailableVehicles();

    rentalSystem.rentVehicle(user1, "Tesla");
    rentalSystem.rentVehicle(user1, "Porsche");

    return 0;
}