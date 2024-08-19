/* 	Thomas Dela Pena
	z1920111
	CSCI 340-1
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/
// include other header files (if any)
#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "btree.h"

template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
public:
    void Insert(const T &x);       // inserts node with value x
    bool Search(const T &x) const; // searches leaf with value x
    bool Remove(const T &x);       // removes leaf with value x
private:
    void _Insert(Node<T> *&, const T &);      // private version of insert
    bool _Search(Node<T> *, const T &) const; // private version of search
    void _Remove(Node<T> *&, const T &);      // private version of remove
    bool _Leaf(Node<T> *node) const;          // checks if node is leaf
};

// put statements in header 

/*
*   Inserts a node with the data value x in the tree
*
*   @param x value to insert in tree
*/
template <typename T>
void BinarySearchTree<T>::Insert(const T &x)
{
	_Insert(this->root, x);		//call recursive insert function
}

/*
*   Insert Node with value x in teh tree
*
*   @param node pointer to local root
*   @param x value to be inserted
*
*/
template <typename T>
void BinarySearchTree<T>::_Insert(Node<T> *&node, const T &x)
{
    if(node == nullptr)
    {
        node = new Node<T>(x, nullptr, nullptr);    //if node empty, create new node
    }
    else
    {
        if(x < node -> data)
        {
            _Insert(node->left, x);     //if value less than node, go left
        }
        else
        {
            _Insert(node->right, x);    //if value greater than node, go right
        }
    }
}

/*
*   Search for value x
*
*   @param x value being searched for
*
*   @note If x is found, return true. Otherwise, return false
*/
template <typename T>
bool BinarySearchTree<T>::Search(const T &x) const
{
	return _Search(this->root, x);		//call recursive search function
}

/*
*   Search for value x
*
*   @param node pointer to a local root node
*   @param x value being searched for
*
*   @return bool value
*   @note If x is found, return true. Otherwise, return false
*/
template <typename T>
bool BinarySearchTree<T>::_Search(Node<T> *node, const T &x) const
{
    if(node == nullptr)
    {
        return false;   //when node is empty, value not found
    }
    else if(node->data == x)
    {
        return true;    //value is found
    }
    else if(node->left != nullptr && node->data > x)
    {
        return _Search(node->left, x);      //if value less then node, go left
    }
    else if(node->right != nullptr && node->data < x)
    {
        return _Search(node->right, x);     //if value greater than node, go right
    }
    else
    {
        return false;
    }
}

/*
*   Searches a leaf with the value of x to remove
*
*   @param x value to be removed
*
*   @return bool value
*   @note calls if leaf is removed, return true. Else, return false.
*/
template <typename T>
bool BinarySearchTree<T>::Remove(const T &x)
{
    if(Search(x) == true)
    {
        _Remove(this->root, x);   //call private Remove() function
        return true;
    }
    else
    {
        return false;
    }
}
/*
*   Remove the node with value x
*
*   @param node pointer to local root
*   @param x value to be removed
*
*   @note search value to be removed
*/
template <typename T>
void BinarySearchTree<T>::_Remove(Node<T> *&node, const T &x)
{
  Node<T>* temp = node;

  if(node->left == nullptr)
  {
      //Reattach the right child or nullptr
      node = node->right;
      delete temp;
  }
  else if(node->right == nullptr)
  {
      node = node->left;
      delete temp;
  }
  else
  {
      //get predecessor node
      while(node->right != nullptr)
      {
          node = node->right;
      }

      node->data = x;
      _Remove(node->left, x);
  }

}

/*
*   Check if node is a leaf
*
*   @param node node to check if it is a leaf
*
*   @return bool value
*/
template <typename T>
bool BinarySearchTree<T>::_Leaf(Node<T> *node) const
{
    //if left and right node are empty, then it's a leaf
    if(node->left == nullptr && node->right == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}


#endif // End of BINARYSEARCHTREE_H_