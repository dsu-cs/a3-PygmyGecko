#pragma once

// include this library to use NULL, otherwise use nullptr instead
#include <cstddef>
#include <iostream>
#include "node.hpp"

template<class T>
class BST{
public:
    // Constructor for the BST class, creates an empty tree
    BST(void);
    // Destructor for the BST class, destroys the tree
    ~BST(void);
    // Inserts data into the tree
    // param: The data to be inserted into the tree
    void insert(T);
    // Removes data from the tree
    // param: The data to be removed from the tree
    void remove(T);
    // Performs an inorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *inorder(void);
    // Performs an postorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *postorder(void);
    // Performs an preorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *preorder(void);
    // Searches the tree for a given value
    // param: the data to search for
    // returns: a pointer to the node containing the data or NULL if the data
    //          was not found
    Node<T> *search(T);
    // Gets the current number of nodes in the tree
    // returns: the number of nodes in the tree
    int get_size(void);
private:
    // the root node of the tree
    Node<T> *root;
    // the number of nodes in the tree
    int node_count;
};

template<class T>
BST<T>::BST()
{
    root = NULL;
    node_count = 0;
}

template<class T>
BST<T>::~BST()
{
    root = NULL;
    while(root != NULL)
    {
        remove(root->get_data());
    }
}

template<class T>
 std::vector<T> * BST<T>::inorder()
{
    std::vector<T> *vec = new std::vector<T>;

    return vec;
}


template<class T>
 std::vector<T> * BST<T>::preorder()
{
    std::vector<T> *vec = new std::vector<T>;
    return vec;
}


template<class T>
 std::vector<T> * BST<T>::postorder()
{
    std::vector<T> *vec = new std::vector<T>;

    return vec;
}

template<class T>
void BST<T>::insert(T new_data)
{
    Node<T> *node = new Node<T>(new_data);
    Node<T> *cur;

    if(root == NULL){
        root = node;
    } else {
        cur = root;
        while(cur != NULL){
            if((*node).get_data() < (*cur).get_data()){
                if((*cur).get_left() == NULL){
                    (*cur).set_left(node);
                    (*cur).set_left(NULL);
                } else {
                    (*cur).set_left((*cur).get_left());
                }
            } else {
                if((*cur).get_right() == NULL){
                   (*cur).set_right(node);
                    (*cur).set_right(NULL);
                } else {
                    (*cur).set_right((*cur).get_right());
                }
            }
        }
    }

    node_count++;
    return;
}


template<class T>
Node<T> *BST<T>::search(T val)
{
    Node<T> *cur = root;

    while(cur != NULL){
        if((*cur).get_data() == val){
            return cur;
        } else if(val < (*cur).get_data()){
            cur = (*cur).get_left();
        } else {
            cur = (*cur).get_right();
        }
    }
    return NULL;
}



template<class T>
void BST<T>::remove(T val)
{

}



template<class T>
int BST<T>::get_size()
{
    return node_count;
}