#include <iostream>
using namespace std;

class MyComplex
{
private:
	double real, imag;
public:
	MyComplex(){
		real = 0; 
		imag = 0;
	}

	MyComplex(double r, double i) {
		real = r;
		imag = i;
	}

	double getReal() const {
		return real;
	}

	double getImag() const {
		return imag;
	}

	MyComplex & operator=(const MyComplex &);
	const MyComplex operator+(const MyComplex & );
	MyComplex & operator++(void);
	const MyComplex  operator++(int);

	/*friend const 
		MyComplex operator+(const MyComplex&, const MyComplex&); */

	//friend ostream& operator<<(ostream& os, const MyComplex& c);
	friend ostream& operator<<(ostream& os, const MyComplex& c);

        // note: no const for the second parameter
        friend istream& operator>>(istream& is, MyComplex& c);
};

MyComplex & MyComplex::operator=(const MyComplex& c) {
	real = c.real;
	imag = c.imag;
	return *this;
}

const MyComplex MyComplex::operator+(const MyComplex& c) {
	MyComplex temp;
	temp.real = this->real + c.real;
	temp.imag = this->imag + c.imag;
	return temp;
}

//pre-increment
MyComplex & MyComplex::operator++() {
	real++;
	imag++;
	return *this;
}

//post-increment
const MyComplex MyComplex::operator++(int) {
	    MyComplex temp = *this;
	    real++;
	    imag++;
	    return temp;
}

/* This is not a member function of MyComplex class */
/*
const MyComplex operator+(const MyComplex& c1, const MyComplex& c2) {
	    MyComplex temp;
	    temp.real = c1.real + c2.real;
	    temp.imag = c1.imag + c2.imag;
	    return temp;
}*/


//ostream& operator<<(ostream &os, const MyComplex& c) {
//	os << c.real << '+' << c.imag << 'i' << endl;
//	return os;
//}

ostream& operator<<(ostream& os, const MyComplex& c) {
	os << c.real << '+' << c.imag << 'i' << endl;
	return os;
}


istream& operator>>(istream &is, MyComplex& c) {
	is >> c.real >> c.imag;
	return is;
}

int main()
{
	MyComplex c1(5,10);
	MyComplex c2(25,20);
	

	c2 = c1++;
	c2++;

	cout << c2 ;
	//cout << c2;
	//cout << "c1 = " << c1.getReal() << "+" << c1.getImag() << "i" << endl;

	//cout << "Using overloaded ostream(<<) " << endl;
	//cout << "c1 = " << c1 << endl;

	//MyComplex c2;
	//cout << "Enter two numbers: " << endl;
	//cin >> c2;
	//cout << "Using overloaded istream(>>) " << endl; 
	//cout << "Input complex is = " << c2;

    // wait until user is ready before terminating program
    // to allow the user to see the program results
    system("PAUSE");
	return 0;
}