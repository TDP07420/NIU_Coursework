	#include <iostream>
	#include <iomanip>
	#include <fstream>
	using namespace std;

	int main()
	{
 	    int i = 0x87654321;
	    char u[5] = "unix";

	    ofstream myfile;
	    myfile.open("fileout.txt", ios::binary);

	    myfile.write((char *)&i, sizeof(i));
	    myfile.write((char *)u, 4);

	    myfile.close();
	}

