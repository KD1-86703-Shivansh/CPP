#include <iostream>
using namespace std;

class Address {
	string building;
	string street;
	string city;
	int pin;
	
public:
	Address()
	{
		building = "";
		street = "";
		city = "";
		pin = 000000;
	}
	Address(string b,string s,string c,int p)
	{
		building = b;
		street = s;
		city = c;
		pin = p;
	}
    string getBuilding() const 
	{
        return building;
    }

    string getStreet() const 
	{
        return street;
    }

    string getCity() const 
	{
        return city;
    }

    int getPin() const 
	{
        return pin;
    }
	

    void setBuilding(const string& b) {
        building = b;
    }

    void setStreet(const string& s) {
        street = s;
    }

    void setCity(const string& c) {
        city = c;
    }

    void setPin(int p) {
        pin = p;
    }
	
	void accept()
	{
		cout << "Enter building: ";
        getline(cin, building);
        cout << "Enter street: ";
        getline(cin, street);
        cout << "Enter city: ";
        getline(cin, city);
        cout << "Enter pin: ";
        cin >> pin;
	}
	
	void display()
	{
		cout << "Building = " << building << endl;
		cout << "Steet = " << street << endl;
		cout << "City = " << city << endl;
		cout << "PIN = " << pin << endl;
	}
};

int main()
{
	Address a1;
	a1.display();
	cout << endl;
	

	Address a2;
	a2.accept();
	cout << endl;
	a2.display();
	cout << endl;
	
	Address a3("Burj Khalifa","XYZ Street","Dubai",562583);
        a3.display();
        cout << endl;
    

    a3.setBuilding("Twin Towers");
    a3.setStreet("Abc Street");
    a3.setCity("Singapore");
    a3.setPin(548752);
    a3.display();
    cout << endl;
    return 0;

}