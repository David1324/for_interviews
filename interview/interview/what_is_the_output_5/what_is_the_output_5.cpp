#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
	Car(string s) :name(s){ cout << "ctor: " << s << endl; }
	string name;
};

class NormalCar : virtual public Car
{
public:
	NormalCar(int d, string s = "NormalCar") : Car(s), displacement(d){}
	int displacement;
};

class ElectricCar : public virtual Car
{
public:
	ElectricCar(int bl, string s = "ElectricCar") : Car(s), batteryLife(bl){}
	int batteryLife;
};

class HybridCar : public NormalCar, public ElectricCar
{

public:
	HybridCar(int p = 50000, int b = 1, int d = 2000, string s = "HybridCar")
		: NormalCar(d, s), ElectricCar(b, s), Car(s), price(p) {}
	int price;
};

int main()
{
	//HybridCar h(65000, 2, 2500, "mcar");
	HybridCar h(65000, 2, 2500);
	cout << "\n\n";
	cout << "name: " << h.name << endl;
	cout << "displacement: " << h.displacement << endl;
	cout << "batterLife: " << h.batteryLife << endl;
	cout << "price: " << h.price << endl;

	getchar();
	return 0;
}