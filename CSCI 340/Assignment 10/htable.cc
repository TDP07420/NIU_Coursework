/* 	Thomas Dela Pena
	  z1920111
	  CSCI 340-1
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/
#include "htable.h"

#define N1 10  // num of decimal digits
#define N2 26  // num of upper-case letters

// Hash function, you may NOT modify this function
int HT::hash(const string &s) {
  int n = (N2 * N1) * (s[0] - 'A') + N1 * (s[1] - 'A') + (s[2] - '0');

  return n % hsize;
}

// You will complete the code below ...
/*
*   The hash table constructor
*
*   @param hs pointer to a fixed size of hash table
*/
HT::HT(const unsigned &hs) : hsize(hs), hTable(hs){}

/*
*   Destructor of the hash table
*/
HT::~HT() 
{
    for(unsigned i = 0; i < hTable.size(); ++i)
    {
      hTable[i].clear();    //clears the inside of hTable
    }

    hTable.clear();         //clear hTable
    pTable.clear();         //clear pTable
}

/*
*   inserts record of the item in the hash table
*
*   @param e record being put in hash table
*/
void HT::insert(const Entry &e) 
{
    int input = hash(e.key);        //value of hash

    list<Entry>& l = hTable[input];     //list to put value in

    auto ptr = find_if(l.cbegin(), l.cend(), [e](const Entry& x)
    {
      return e.key == x.key;        //return when key is found
    });

    if(ptr == l.cend())       //if new then insert
    {
      std::cout << "entry = " << input << std::endl;
      hTable[input].push_back(e.key);   //put e key  in hash table
    }
    else                            //not new, print error
    {
        std::cout << "not inserted - duplicated key!!!" << std::endl;
    }
}

/*
*   Searches the hash tables for a record with key
*
*   @param s key bring searched for in hash table
*/
void HT::search(const string &key) 
{
    int input = hash(key);    //value representing the key

    list<Entry>& l = hTable[input];   

    auto ptr = find_if(l.cbegin(), l.cend(), [key](const Entry& x)
    {
        return key == x.key;
    });

    if(ptr == l.cend())     //search not successful, send error message
    {
        std::cout << "key " << key << " not in table!!" << std::endl;
    }
    else                    //search successful, print info for the record
    {
        std::cout << " ==> number: " << hTable[input].front().num << " - item: " << hTable[input].front().desc << std::endl;
    }
}

/*
*   Prints the subscript and the contents of all (and only) the 
*   active records in the hash table
*/
void HT::hTable_print() 
{
   /* for(unsigned int i = 0; i < hsize; ++i)
    {
        if(hTable[i].front().key != "---")    //print if hash spot is occupied
        {
          std::cout << std::endl;
          std::cout << i << ": " << hTable[i].front().key <<
          hTable[i].front().desc << std::endl;
          std::cout << std::endl;
        }
    }*/
}

/*
*   Prints the contents of all (and only) the 
*   active records in the hash table.
*/
void HT::pTable_print() 
{
    bool cmp(Entry *p, Entry *q);     //component of comparison

    std::sort(pTable.begin(), pTable.end(), cmp);
   
    //print results
    for (unsigned int i = 0; i < pTable.size(); i++)
    {
        std::cout << " " << pTable[i]->key << " - " << pTable[i]->num <<
        " - " << pTable[i]->desc << std::endl;
    }

    std::cout << std::endl;
} 

/*
*   component of comparison
*
*   @param p one entry for comparison
*   @param q second entry for comparison
*/
bool cmp(Entry *p, Entry *q)
{
    if(p->key < q->key)
    {
      return true;
    }
    else
    {
      return false;
    }
}