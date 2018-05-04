#include <iostream>
#include <string>
#include <sstream>

unsigned int SHF(std::string input)
{
	unsigned int init = 124564352;
	unsigned int magic = 5674356;
	unsigned int hash;

	for (int i = 0; i < input.length(); i++)
	{
		hash = hash ^ (input[i]);
		hash = hash * magic;
	}
	return hash;
}

std::string toHex(unsigned int input)
{
	std::string HexHash;
	std::stringstream hexStream;
	hexStream << std::hex << input;
	HexHash = hexStream.str();
	std::transform(HexHash.begin(), HexHash.end(), HexHash.begin(), ::toupper);
	return HexHash;
}


int main()
{
	std::cout << "test hashed is : " << toHex(SHF("test"));
	getchar();
}

