///*
//* Example of a singleton design pattern.
//* Copyright (C) 2011 Radek Pazdera
//* This program is free software: you can redistribute it and/or modify
//* it under the terms of the GNU General Public License as published by
//* the Free Software Foundation, either version 3 of the License, or
//* (at your option) any later version.
//* This program is distributed in the hope that it will be useful,
//* but WITHOUT ANY WARRANTY; without even the implied warranty of
//* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//* GNU General Public License for more details.
//* You should have received a copy of the GNU General Public License
//* along with this program. If not, see <http://www.gnu.org/licenses/>.
//*/
//
//#include <iostream>
//
//class Singleton
//{
//private:
//	/* Here will be the instance stored. */
//	static Singleton* instance;
//
//	/* Private constructor to prevent instancing. */
//	Singleton();
//
//public:
//	/* Static access method. */
//	static Singleton* getInstance();
//};
//
///* Null, because instance will be initialized on demand. */
//Singleton* Singleton::instance = 0;
//
//Singleton* Singleton::getInstance()
//{
//	if (instance == 0)
//	{
//		instance = new Singleton();
//	}
//
//	return instance;
//}
//
//Singleton::Singleton()
//{}
//
//int main()
//{
//	//new Singleton(); // Won't work
//	Singleton* s = Singleton::getInstance(); // Ok
//	Singleton* r = Singleton::getInstance();
//
//	/* The addresses will be the same. */
//	std::cout << s << std::endl;
//	std::cout << r << std::endl;
//	getchar();
//}






















#include <iostream>

using namespace std;

//using std::cout;
//using std::endl;

#define NULL 0

class David
{
private:
	David();
	static David* instance;
	//David* instance;
public:
	static David* create_instance();
};

David::David() {}

David* David::instance = NULL;
//David* instance = NULL;
David* David::create_instance()
{
	if (instance == NULL)
	{
		instance = new David();
	}
	return instance;
}

int main()
{
	//David d; //compilation error since the constructor is private.
	David* d1 = David::create_instance();
	David* d2 = David::create_instance();
	if (d1 == d2)
	{
		cout << "d1 = " << d1 << endl;
		cout << "d2 = " << d2 << endl;
		cout << "class David is singelton!" << endl;
	}
	else
	{
		cout << "class David is NOT singelton!" << endl;
	}
	getchar();
	return 0;
}