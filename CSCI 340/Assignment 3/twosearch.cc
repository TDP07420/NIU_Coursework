/* 	Thomas Dela Pena
	z120111
	CSCI 340 Section 1
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/
#include "twosearch.h"

#include <getopt.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>


/**
* see: 
* https://en.wikipedia.org/wiki/Usage_message
* https://www.ibm.com/docs/en/aix/7.2?topic=commands-usage-statements
*
* @param a0 The value of argv[0] (the name of the command) so that it 
*   can be printed.
*
* @note This function will terminate the application via exit(1).
******************************************************************************/
static void usage(const char *a0)
{
    std::cerr << "Usage: " << a0 << " [-l rand_low] [-h rand_high] [-a a_size] [-b b_size] [-x a_seed] [-y b_seed] [-c print_cols] [-w col_width]" << std::endl;
    std::cerr << "    rand_low   = rand() low bound (default=1)" << std::endl;
    std::cerr << "    rand_high  = rand() high bound (default=1000)" << std::endl;
    std::cerr << "    a_size     = size of vector A (default=200)" << std::endl;
    std::cerr << "    b_size     = size of vector B (default=100)" << std::endl;
    std::cerr << "    a_seed     = random seed for vector A (default=1)" << std::endl;
    std::cerr << "    b_seed     = random seed for vector B (default=3)" << std::endl;
    std::cerr << "    print_cols = number of colums per line (default=16)" << std::endl;
    std::cerr << "    col_width  = printed column value width (default=4)" << std::endl;
    exit(1);
} // End of usage()

/**
* Parse the command-line args, create and sort vector A, create vector B,
* search vector A for those elements appearing in vector B using both
* a linear and binary search, and print the hit-rate (the percentage of 
* items in B that have been located in A.)
*
* If an invalid command-line arg is encountered, print a Usage statement 
* and terminte with an exit-status of 1.
*
* @return zero
******************************************************************************/
int main(int argc, char **argv)
{
    // Demonstrate the use of getopt() to override default config parameters 
    int rand_low = 1;
    int rand_high = 1000;
    int a_size = 200;
    int b_size = 100;
    int a_seed = 1;
    int b_seed = 3;
    int print_cols = 16;
    int col_width = 4;

    int opt;
    // see: http://faculty.cs.niu.edu/~winans/CS340/2022-sp/#getopt
    while ((opt = getopt(argc, argv, "a:b:c:h:l:w:x:y:")) != -1)
    {
        switch(opt)
        {
        case 'a':
            // see https://en.cppreference.com/w/cpp/string/basic_string/stol
            a_size = std::stoi(optarg); // override the default for a_size
            break;

        case 'b':
            b_size = std::stoi(optarg);
            break;
        case 'c':
            print_cols = std::stoi(optarg);
            break;
        case 'h':
            rand_high = std::stoi(optarg);
            break;
        case 'l':
            rand_low = std::stoi(optarg);
            break;
        case 'w':
            col_width = std::stoi(optarg);
            break;
        case 'x':
            a_seed = std::stoi(optarg);
            break;
        case 'y':
            b_seed = std::stoi(optarg);
            break;
            
        default:
            // got an arg that is not recognized...
            usage(argv[0]);     // pass the name of the program so it can print it
        }
    }

    // Make sure there are not any more arguments (after the optional ones)
    if (optind < argc)
        usage(argv[0]);

    // Add application logic here...
	
    std::vector<int> A;				//Define two vectors
    std::vector<int> B;

    A.resize(a_size);
    B.resize(b_size);

    init_vector(A, a_seed, rand_low, rand_high);	//Pass vectors through init_vector()	
    init_vector(B, b_seed, rand_low, rand_high);

    print_vector(A, print_cols, col_width);		//Print the elements of vector A

    sort_vector(A);					
    print_vector(A, print_cols, col_width);		//Print vector A, after sorted

    print_vector(B, print_cols, col_width);		//Print vector B
    
    int found;

    found = search_vector(A, B, &linear_search);	

    std::cout << "Linear Search: ";
    print_stat(found, a_size);				//print linear search results

    found = search_vector(A, B, &binary_search);

    std::cout << "Binary Search: ";
    print_stat(found, a_size);				//print binary search results
    
    return 0;

} // End of main()

/*
*	Assign random valued to the elements in a vector by using a seeded value
*
*	@param vec  vector where value needs assignment
*	@param seed value of the seed needed to initialize random number generator(rng)
*	@param lo   value of the lowest value for the range of rng
*	@param hi   value of the highest value for the range of rng
*/
void init_vector(std::vector<int> &vec, int seed, int lo, int hi)
{
	srand(seed);	//initializing the random number seed
	
	int v_size = vec.size();

	for (int i = 0; i < v_size; i++)
	{
		vec.push_back(rand()%(hi-lo+1)+lo);
	}
}

/*
*       Print out a given vector
*
*       @param v  reference to vector given to print
*       @param print_cols value of the amount of elements printed out on each line
*       @param col_width value of the width of each printed numeric value is padded out
*       
*/
void print_vector(const std::vector<int> &v, int print_cols, int col_width)
{
	for ( int i = 0; i < print_cols; i++)
	{
		std::cout << "| " << std::setw(col_width) << v[i];
	}
	
	std::cout << "|" << std::endl;

}

/*
*       Sort the given vector in ascending order
*
*       @param v  reference to vector given to sort       
*/

void sort_vector(std::vector<int> &v)
{
	std::sort(v.begin(), v.end());	//sort the vector
}

/*
*       Search for elements of one vector inside another given vector
*
*       @param v1  reference to vector given being searched
*       @param v2  reference to vector where the elements are being searched
*       @param p   pointer to a search routine
*
*	@return    number of successful searches
*/
int search_vector(const std::vector<int> &v1, const std::vector<int> &v2, bool (*p)(const std::vector<int> &, int))
{
	int success = 0;
	int v1_size = v1.size();

	for (int j = 1; j < v1_size; j++)
	{
		if(p(v2, v2.at(j)))
		{
			success++;
		}
	}

	return success; 
}

/*
*       Print the percent of successful searches 
*
*       @param found value of total number of successful searches
*       @param total size of the test vector being searched.
*/
void print_stat(int found, int total)
{
	float succSearch;

	succSearch = (found / total) * 100;

	std::cout << "Percent of Successful Searches = " << std::setprecision(4) << succSearch
        << std::endl;

}

/*
*       Implementation of the linear search algorithm
*
*       @param v vector being searched
*       @param x value to search for 
* 
*	@return result if search is successful
*/

bool linear_search(const std::vector<int> &v, int x)
{
	std::vector<int>::const_iterator result;	//declare result iterator for search

	result = find(v.begin(), v.end(), x);		//apply find() using iterator

	if(result != v.end())
	{
		return true;	//element found
	}
	else
	{
		return false;	//element not found
	}

}

/*
*       Implementation of the binary search algorithm
*
*       @param v vector being searched
*       @param x value to search for
*
*       @return return if result is successful
*/
bool binary_search(const std::vector<int> &v, int x)
{
        if(binary_search(v.begin(), v.end(), x))
        {
                return true;    //element found
        }
        else
        {
                return false;   //element not found
        }

}




