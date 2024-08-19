/* 	Thomas Dela Pena
	z1920111
	CSCI 340-1

	I certify that this is my own work and where appropriate an extension
	of the starter code provided for the assignment.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <cctype>

using std::map;
using std::pair; 
using std::string;

//function prototypes
void get_words(map<string, int>&);
void print_words(const map<string, int>&);
void clean_entry(const string&, string&);

int main()
{
	//declaring variables
	string input;
	map<string, int> storage;		//for initial storage
	

	//put input stream into 'input
	getline(std::cin, input);

	//std::cout << input;					//testing inputstream

	std::stringstream iss(input);

	while (iss)
	{
		string substr;
		getline(iss, substr,' ');
		int count = 0;
		auto pos = input.find(substr, 0);

		while (pos != string::npos)
		{
			++count;						//increase count of occurence
			pos = input.find(substr, pos + 1);
		}

		//store the substring into storage
		if (substr.size() != 0)
		{
			storage[substr] = count;
		}
	}

	get_words(storage);

	print_words(storage);

	/*for (const auto& p : storage)
	{
		std::cout << p.first << " = " << p.second << "\n";
	}*/
	return 0;
}

/*
*	Gets a word from the input stream and removes its punctuation marks
* 
*	@param stg reference to a map that stores words from the input stream
*/
void get_words(map<string, int>& stg)
{
	string ostring;		//original string
	string clstring;	//final cleanup string

	clean_entry(p.first, clstring);
	

	if (clstring.length() > 0)
	{
		stg[clstring]++;
	}
}

/*
*	Cleans a word from its punctuation marks
* 
*	@param  o_word reference to a string containing the original word from input stream
*	@param  cl_word reference to a string containing the new word after cleaning
*/
void clean_entry(const string& o_word, string& cl_word)
{
	size_t i = 0;				//1st index
	size_t j = 0;				//2nd index
	
	while (!isalnum(o_word[i]) && i < o_word.length())
	{
		i++;
	}
	j = i;
	while (!isalnum(o_word[j]) && j < o_word.length())
	{
		j++;
	}

	cl_word = o_word.substr(i, (j - i));




}