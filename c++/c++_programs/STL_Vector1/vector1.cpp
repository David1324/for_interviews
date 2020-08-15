#include <vector>
#include <iostream>
#include <string>

int main()
{
	std::vector<std::string> Scientist;

	Scientist.push_back("James Maxwell");
	Scientist.push_back("Edwin Hubble");
	Scientist.push_back("Charles Augustin de Coulomb");
	Scientist.push_back("Louis Pasteur");

	std::cout << "Now, we have " << Scientist.size() << " scientists.\n";
	Scientist.pop_back();
	std::cout << "Now, we have " << Scientist.size() << " scientists.\n";

	std::vector<std::string>::iterator iter;
	for (iter = Scientist.begin(); iter != Scientist.end(); ++iter)
	{
		*iter = *iter + "_hi"; //with const_iterator it can't happen
		std::cout << *iter << std::endl;
	}
		

	Scientist.clear();
	if (Scientist.empty())
		std::cout << "Nothing in the list\n";
	else
		std::cout << "You have something in the list\n";

	getchar();
	return 0;
}