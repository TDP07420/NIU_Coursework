/* 	Thomas Dela Pena
	z1920111
	CSCI 340 Section 1

	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

  
#include "josephus.h"

#include <list>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <getopt.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::list;

void print_underlined_string(const string &message);
void print_list(const list<string> &collection, const unsigned &eliminations, int num_cols);

/**
* Print a 'Usage' message and exit(1).
*
* @param a0 The name of the command to include in the usage message.
*****************************************************************************/
static void usage(const char *a0)
{
    std::cerr << "Usage: " << a0 << " [-n number of people] [-m modulus] [-p print frequency] [-c print columns]" << std::endl;
    exit(1);
}


/**
* Create a std::list of prople with generated ID/names and reduce the
* list as per the Josephus problem algorithm.
*****************************************************************************/
int main(int argc, char **argv)
{
    unsigned num_people = 41;       // The number of people to start with
    unsigned modulus = 3;           // The count used to determine the elimination
    unsigned print_frequency = 13;  // How often to print the state of the system
    unsigned num_cols = 12;         // Number of colums to print per line

    int opt;
    while ((opt = getopt(argc, argv, "n:m:p:c:")) != -1)
    {
        switch (opt)
        {
        case 'n':
            std::istringstream(optarg) >> num_people;
            break;
        case 'm':
            std::istringstream(optarg) >> modulus;
            break;
        case 'p':
            std::istringstream(optarg) >> print_frequency;
            break;
        case 'c':
            std::istringstream(optarg) >> num_cols;
            break;
        default:
            usage(argv[0]);
        }
    }

    if (optind < argc)
        usage(argv[0]); // If we get here, there was extra junk on command line

    //********************beginning of implementation of main************************************
    
    std::list<string> collection;
    unsigned int elimination = 0;

    std::generate_n(std::back_inserter(collection), num_people, SEQ(num_people));

    print_list(collection, elimination, num_cols);

    //declare collection iterator
    auto c_it = collection.begin();

    while (collection.size() > 1)
    {
        for (unsigned int i = 1; i < modulus; i++)
        {
            //increment collection iterator.
            ++c_it;

            if (c_it == collection.end())
            {
                c_it = collection.begin();
            }
        }

        c_it = collection.erase(c_it);
        elimination++;

        if (c_it == collection.end())
        {
            c_it = collection.begin();
        }

        if (elimination % print_frequency == 0)
        {
            print_list(collection, elimination, num_cols);
        }
    }
    
    //Final print
    cout << "Eliminations Completed" << endl;
    print_list(collection, elimination, num_cols);


	



  return 0;
}// End of main()

/*
*   Print a heading including the number of eliminations and the contents of collections.
* 
*   @param collection reference to a constant list needed for eliminations
*   @param elimination value representing amount of eliminations being processed
*   @param num_cols value of amount of elements being printed per column
*/
void print_list(const list<string> &collection, const unsigned &eliminations, int num_cols)
{
    string in_str = "Initial group of people";
    
    //Create 2nd string heading
    std::ostringstream oss;
    oss << "After eliminating " << eliminations << " people";
    string af_str = oss.str();	
    
    //determine heading
    if (eliminations == 0)
    {
        cout << in_str << endl;
        print_underlined_string(in_str);
        cout << endl;
    }
    else
    {
        cout << af_str << endl;
        print_underlined_string(af_str);
    }

    int count = 1;                          //count elements per line
    unsigned int c_count = 1;               //count total elements
    //print contents of collection
    for (auto it = collection.cbegin(); it != collection.cend(); ++it)
    {  
        
        cout << *it;

        if (c_count == collection.size())    //remove comma from last line
        {
            cout << endl;
            c_count = 0;
        }
        else if (count != num_cols)
        {
            cout << ", ";
        }
        else if (count == num_cols)  //prints new line
        {
            cout << endl;

            count = 0;
        }

        count++;
        ++c_count;
    }

    cout << endl;
}

/*
*   Print the given message with an underline that matches the length of the message
*   text.
* 
*   @param message message given that needs to be underlined
*
*   @note use this to create the heading in print_list()
*/
void print_underlined_string(const string &message)
{
	for(unsigned int i; i < message.size(); ++i)
	{
		cout << "-";
	}
	
	cout << endl;
}

