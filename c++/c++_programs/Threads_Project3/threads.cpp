#include <iostream>
#include <thread>

void cpp11()
{
	std::cout<<"C++11 MULTITHREADING\n";
}

int main()
{
	std::thread t(cpp11);
	t.join();
}