/* 	Thomas Dela Pena
	z120111
	CSCI 340 Section 1
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

#include "car.h"
#include "garage.h"

#include <iostream>
#include <cstdio>
#include <string>
#include <deque>
#include <stack>

void get_input_vals(const std::string& line, char& xact_type, std::string& license);

using std::cin;

int main()
{
	//declaring values
	garage scratch;
	std::string line;
	std::string c_license;
	char act;
	
	while (cin)
	{
		std::getline(cin, line);

		//std::cout << "Line= " << line << std::endl;
		

		get_input_vals(line, act, c_license);		//obtain data from line

		//std::cout << "license= " << c_license << std::endl;	//*******Testing output*********
		//std::cout << "act= " << act << std::endl;

		if (act == 'A')
		{
			scratch.arrival(c_license);
		}
		/*else if (act == 'D')
		{
			scratch.departure(c_license);
		}*/
		else
		{
			std::cout << "'" << act << "': invalid action!" << std::endl;
		}

		std::cout << std::endl;
	}
	return 0;
}

/*
*	Extracts individual componenets from the input line line, 
*
*	@param line input line being extracted
*	@param xact_type indicator if line corresponds with an arrival or departure event
*	@param license license plate number of arriving/deparing vehicle
*/
void get_input_vals(const std::string& line, char& xact_type, std::string& license)
{
	xact_type = line[0];			//get act
	license = line;
	std::string delimiter = ":";

	//parse line
	size_t pos = 0;
	std::string token;
	while ((pos = license.find(delimiter)) != std::string::npos) {
		token = license.substr(0, pos);
		license.erase(0, pos + delimiter.length());
	}

	license = token;	//obtain license num
	
}