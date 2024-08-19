/* 	Thomas Dela Pena
	z1920111
	CSCI 340-1

	I certify that this is my own work and where appropriate an extension
	of the starter code provided for the assignment.
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <cctype>

using std::map;
using std::pair; 
using std::string;
using std::setw;

//function prototypes
void get_words(map<string, int>&);
void print_words(const map<string, int>&);
void clean_entry(const string&, string&);

//constant variables
const int NO_ITEMS = 4;
const int ITEM_WORD_WIDTH = 14;
const int ITEM_COUNT_WIDTH = 3;

int main()
{
	//declaring variables
	map<string, int> storage;		//for initial storage
	
	get_words(storage);				//call to get words
		
	print_words(storage);			//call to print words

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

	while (std::cin)			//get input from stream
	{	
		std::cin >> ostring;	//acquire original word
		clean_entry(ostring, clstring);


		if (clstring.length() > 0)	//if length > 0, add to storage
		{
			stg[clstring]++;
		}
	}
}

/*
*	Cleans a word from its punctuation marks
* 
*	@param  o_word reference to a string containing the original word from input stream
*	@param  cl_word reference to a string containing the new word after cleaning
* 
*	@note removes punctuatation and converts word into lowercase
*/
void clean_entry(const string& o_word, string& cl_word)
{
	size_t i = 0;				//1st index
	//size_t j;				//2nd index
	

	while (isalnum(o_word[i]))		//removing punctuations
	{
		//get clean word
		cl_word = o_word.substr(0, i + 1);
		i++;
	}

	//put clean words into lowercase
	for_each(cl_word.begin(), cl_word.end(), [](char& c) {c = std::tolower(c); });
}

/*
*	Prints the final list of words and their frequencies. Also prints the number of nonempty 
*	words and the number of distinct words in the input stream
* 
*	@param m reference to a map containing the list of words to be printed.
*/
void print_words(const map<string, int>& m)
{
	int count = 0;		//num for words per line
	int words = 0;		//num of words in input stream

	//print words and frequency
	for (auto i : m)
	{
		std::cout << std::left << setw(ITEM_WORD_WIDTH) << i.first << ":" << setw(ITEM_COUNT_WIDTH) 
			<< i.second;
		count++;
		words += i.second;

		if (count == NO_ITEMS)		// 4 words per line
		{
			std::cout << std::endl;
			count = 0;				//reset count
		}
	}

	//print total result
	std::cout << "\nnumber of words in input stream   :" << words << std::endl; 
	std::cout << "number of words in output stream  :" << m.size() << std::endl;
}