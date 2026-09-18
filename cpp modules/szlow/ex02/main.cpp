#include <iostream>
#include <string>

int	main()
{
	std::string		text = "HI THIS IS BRAIN";
	std::string*	stringPTR = &text;
	std::string&	stringREF = text;

	std::cout << "string address   : " << &text << "\n"
		<< "stringPTR address: " << stringPTR << "\n"
		<< "stringREF address: "<< &stringREF << "\n\n"
		<< "string value   : " << text << "\n"
		<< "stringPTR value: " << *stringPTR << "\n"
		<< "stringREF value: " << stringREF << std::endl;
	return 0;
}