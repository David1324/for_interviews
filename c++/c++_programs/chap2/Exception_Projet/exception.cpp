#include <iostream>
#include <exception>
using namespace std;

class child_exception: public exception {
  virtual const char* what() const throw(){
    return "child exception occurred";
  }
}; 

int main () {
  try {
    child_exception cex;
    throw cex;
  }
  catch (exception& e) {
    cout << e.what() << endl;
  }

    // wait until user is ready before terminating program
    // to allow the user to see the program results
    system("PAUSE");
  return 0 ;
}