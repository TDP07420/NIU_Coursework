/* 	Thomas Dela Pena
	z1920111
	CSCI 340-1
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/
#ifndef H_BTREE
#define H_BTREE

#include "node.h"

template <typename T> class BinaryTree{

public:
    BinaryTree();                                      // default constructor
    unsigned     getSize() const;                      // returns size of tree
    unsigned     getHeight() const;                    // returns height of tree
    virtual void Insert(const T&);                     // inserts node in tree
    void         Inorder(void (*)(const T&));          // inorder traversal of tree

protected:
    Node<T> *root;                                      // root of tree

private:
    unsigned _getSize(Node<T> *) const;                 // private version of getSize()
    unsigned _getHeight(Node<T> *) const;               // private version of getHeight()
    void     _Insert(Node<T> *&, const T&);             // private version of Insert()
    void     _Inorder(Node<T> *, void (*)(const T&));   // private version of Inorder()
};

typedef enum {left_side, right_side } SIDE;

SIDE rnd(){ 
    return rand()%2 ? right_side : left_side;
}// End of rnd()

/*
*   Default Constructor
*/
template <typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;         //construct an empty tree
}

/*
*   Function to insert a node in a binary tree
*
*   @param x value being inserted in a binary tree
*
*   @note This function is virtual
*/
template <typename T>
void BinaryTree<T>::Insert(const T &x)
{
    _Insert(root, x);   //recursive insert 
}

/*
*   Function to insert a node into a random side
*
*   @param r root of the binary tree
*   @param x value being inserted in the binary tree
*   
*   @note SIDE rnd() randomly selects left/right side
*/
template <typename T>
void BinaryTree<T>::_Insert(Node<T> *&r, const T &x)
{
    //insert here if root is empty
    if(r == nullptr)
    {
        r = new Node<T>(x, nullptr, nullptr);
    }
    else
    {
        if(rnd() != right_side) //chose rnd left/right side
        {
            _Insert(r -> left, x);
        }
        else
        {
            _Insert(r -> right, x);
        }
    }
}

/*
*   Get the size of the binary tree
*   
*   @return amount of node in the binary tree
*/
template <typename T>
unsigned BinaryTree<T>::getSize() const
{
        return _getSize(root);  //recursive _getSize  
}

/*
*   Count the amount of nodes in the binary tree
*
*   @param r Root of the binary tree
*
*   @return amount of node in the binary tree
*
*   @note This function is the private getSize function
*/
template <typename T>
unsigned BinaryTree<T>::_getSize(Node<T> *r) const
{
    if(r == nullptr)    //if root is empty, size = 0
    {
        return 0;
    }
    else
    {
        return _getSize(r -> left) + _getSize(r -> right) + 1; //recursion
    }
}

/*
*   Get the height of the binary tree
*
*   @return The height of the binary tree
*/
template <typename T>
unsigned BinaryTree<T>::getHeight() const
{
        return _getHeight(root);    //access private getHeight
}

/*
*   Get the height of the binary tree
*
*   @param r Root of the binary tree
*
*   @return The height of the binary tree
*
*   @note This is the private get Height function
*/
template <typename T>
unsigned BinaryTree<T>::_getHeight(Node<T> * r) const
{
    if (r == nullptr)       //if root is empty, size = 0;
    {
        return 0;
    }
    else
    {
        int Lheight = _getHeight(r -> left);    //find height for left side
        int Rheight = _getHeight(r -> right);   //find height for right side

        if(Lheight > Rheight)   //find max height
        {
            return Lheight + 1;
        }
        else
        {
            return Rheight + 1;
        }
    }
}

/*
*   Traverse the binary tree using inorder traversal
*
*   @param p Pointer to a function
*/
template <typename T>
void BinaryTree<T>::Inorder(void (* p) (const T&))
{
        _Inorder(root, p);  //access private Inorder
}

/*
*   Traverse all nodes in the binary tree using inorder traversal
*
*   @param r pointer to the root of the binary tree
*   @param p pointer to a function
*/
template <typename T>
void BinaryTree<T>::_Inorder(Node<T> *r, void(* p)(const T&))
{
    if (r != nullptr)       //if root not empty, traverse using inorder
    {
        _Inorder(r -> left,p);
        p(r -> data);
        _Inorder(r -> right,p);
    }
}





#endif // End of H_BTREE
