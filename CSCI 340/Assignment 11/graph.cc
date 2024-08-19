/*	Thomas Dela Pena
	z1920111
	CSCI 340-1

	I certify that this is my own work and where appropriate an extension
	of the starter code provided for the assignment.
*/
#include "graph.h"

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>

bool *visited;
std::string edge;


/*
*   Private function used to traverse a graph using 'depth-first search'
*
*   @param v starting vertex where the traversal will begin
*/
void Graph::Depthfirst(int v) 
{
    visited[v] = true;

    std::cout << labels[v] << " ";  //visit vertex
    std::list<int>::iterator it;

    int pos = 0;                    //positional value
    for(it = adj_list[v].begin(); it != adj_list[v].end(); ++it)
    {
        int w = *it;
        if(!visited[w])
        {
            //print the path took
            edge += std::string("(") + labels[v] + std::string(", ") + labels[pos] + std::string(") ");    
        }
        pos++;
    }
}

/*
*   Constructor of the graph
*/
Graph::Graph(const char* filename)
{
    std::ifstream infile;    //open file
    infile.open(filename);
    if(!infile)         //check if file is open
    {
        std::cerr << "Input file not open" << std::endl;
        exit(1);    
    }

    infile >> size;     //get the size of the graph
    std::string temp;

    //get variables of graph
    for(int i = 0; i < Getsize(); i++)
    {
        infile >> temp;
        labels.push_back(temp[0]);
    }
    //get values to create graph
    for(int i = 0; i < Getsize(); i++)
    {
        infile >> temp;
        adj_list.push_back(*(new std::list<int>()));
        for(int j = 0; j < Getsize(); j++)
        {
            int value;
            infile >> value;
            adj_list[i].push_back(value);
        }
    }

    infile.close();     //close file
}

/*
*   Destructor of the graph
*/
Graph::~Graph()
{

}

/*
*   Obtain size of graph
*/
int Graph::Getsize() const 
{ 
  return size;
}

/*
*   Traverses a graph using DepthFirst
*/
void Graph::Traverse() 
{
    std::cout << "------- traverse of graph ------" << std::endl;

    visited = new bool[Getsize()-1];     //tracked visited vertices
    for(int i = 0; i < Getsize(); i++)
    {
        visited[i] = false;
    }

    //if vertex not visited, invoke Depthfirst traversal
    for(int i = 0; i < Getsize(); i++)
    {
        if(!visited[i])
        {
            Depthfirst(i);
        }
    }
    delete[] visited;

    std::cout << "\n" << edge << std::endl;
    std::cout << "--------- end of traverse -------" << std::endl;
}

/*
*   Print the graph
*/
void Graph::Print() const 
{
    //print size of graph
    std::cout << "Number of vertices in the graph: " << Getsize() << std::endl;
    std::cout << "\n-------- graph -------" << std::endl;

    //print graph
    for(int i = 0; i < Getsize(); i++)
    {
        std::cout << labels[i] << ": ";
        int val = 0;
        
        for(std::list<int>::const_iterator it = adj_list[i].begin(); it != adj_list[i].end(); ++it)
        {
            if(*it == 1)
            {
                std::cout << labels[val] << ", ";
            }
            val++;
        }
        std::cout << std::endl;
    }

    std::cout << "------- end of graph ------\n" << std::endl;
}