#include <string>
#include <iostream>
#include <fstream>

void	replaceLine(std::string &line, std::string s1, std::string s2)
{
	size_t	pos = 0;

	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line = line.substr(0, pos) + s2 + line.substr(pos + s1.size());
		pos += s2.size();
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "Requires 3 parameters" << std::endl;
		return 1;
	}

	std::string	inPath = argv[1];
	std::string	outPath = inPath + ".replace";
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	std::string	line;

	std::ifstream	inFile(inPath.c_str());
	if (!inFile.is_open()) {
		std::cerr << "Error: Could not open input file" << std::endl;
		return 1;
	}
	
	std::ofstream	outFile(outPath.c_str());

	while (std::getline(inFile, line))
	{
		replaceLine(line, s1, s2);
		outFile << line;
		if (!inFile.eof())
			outFile << std::endl;
	}

	inFile.close();
	outFile.close();

	return 0;
}