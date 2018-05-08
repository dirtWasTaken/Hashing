#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>


/*************************************************************************************
Hashing function that takes the string inputed in the main function (In this case "test")
and puts it through arithmitic in a for loop and returns the value.
**************************************************************************************/
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

/*************************************************************************************
takes the string input from main ("test") and streams it through the SHF function to 
turn it into a hash code 
**************************************************************************************/
std::string toHex(unsigned int input)
{
	std::string HexHash;
	std::stringstream hexStream;
	hexStream << std::hex << input;
	HexHash = hexStream.str();
	std::transform(HexHash.begin(), HexHash.end(), HexHash.begin(), ::toupper);
	return HexHash;
}

/*************************************************************************************
main fuction simply outputs whatever you wish to input into the hashing algorithm
as a hash code
**************************************************************************************/

int main()
{
	std::cout << "test hashed is : " << toHex(SHF("test"));
	getchar();
}

