#include <memory>
#include <iostream>
#include <vector>
#include "Node.h"

using namespace std;

template <class T>
class Tree {

    public:
        Tree();
        ~Tree();

        shared_ptr<Node<T>> insert(T);
        shared_ptr<Node<T>> find(T);

        int size() const;
        vector<T> getAllAscending();
        void clear();

    protected:
        int size(shared_ptr<Node<T>>) const;
        shared_ptr<Node<T>> insert(shared_ptr<Node<T>>, T);
        shared_ptr<Node<T>> find(shared_ptr<Node<T>>, T);
        vector<T> getAllAscending(shared_ptr<Node<T>>);

    private:
        shared_ptr<Node<T>> root;
        

};


template <class T>
Tree<T>::Tree(){
    // Set the root to nullptr
    root = nullptr;
}

template <class T>
Tree<T>::~Tree(){
    // Clear the list to recursively delete
    clear();
    root = nullptr;
}

template <class T>
shared_ptr<Node<T>> Tree<T>::find(T item){
    // Start the recursion using the root as the first node
    return find(root, item);
}

template <class T>
shared_ptr<Node<T>> Tree<T>::find(shared_ptr<Node<T>> node, T item){

    // First, check if this node's value is equal
    if (node == nullptr) return nullptr;

    // If we found the right item, return it
    if (node->getValue() == item){
        return node;
    }

    // Check recursively if the other nodes have values that aren't nullptr
    if (node->left != nullptr){
        // Check the left side
        shared_ptr<Node<T>> match = find(node->left, item);
        if (match != nullptr) return match;
    }
    if (node->right != nullptr){
        // Check the right side
        shared_ptr<Node<T>> match = find(node->right, item);
        if (match != nullptr) return match;
    }

    return nullptr;

}


template <class T>
shared_ptr<Node<T>> Tree<T>::insert(T item){
    // Start the recursion using the root as the first node
    return insert(root, item);
}

template <class T>
shared_ptr<Node<T>> Tree<T>::insert(shared_ptr<Node<T>> node, T item){

    // If the node doesn't exist, create a new node here
    if (node == nullptr){
        // TODO: Create
        shared_ptr<Node<T>> n(new Node<T>(item));
        if (root == nullptr){
            root = n;
        }
        return n;
    }

    // Set the left node to its new value should it need one
    if (item < node->getValue()){
        node->left = insert(node->left, item);
    }
    // Set the right node to its new value should it need one
    else if(item > node->getValue()) {
        node->right = insert(node->right, item);
    }

    // Return the new modified node
    return node;
}

template <class T>
vector<T> Tree<T>::getAllAscending(){
    // Start the recursion using the root as the first node
    return getAllAscending(root);
}

template <class T>
vector<T> Tree<T>::getAllAscending(shared_ptr<Node<T>> node){
    
    // Create a new vector of values
    vector<T> values;

    // Do not advance if the node we're on is null
    if (node == nullptr) return values;


    // INORDER TRAVERSAL = Left -> Middle -> Right


    // Check the left node tree
    if (node->left != nullptr){
        vector<T> leftValues = getAllAscending(node->left);
        values.insert(values.end(), leftValues.begin(), leftValues.end());
    }

    // Check our current (middle) value
    values.push_back(node->getValue());

    // Check the right node tree
    if (node->right != nullptr){
        vector<T> rightValues = getAllAscending(node->right);
        values.insert(values.end(), rightValues.begin(), rightValues.end());
    }

    // Return the final list of this recursion
    return values;
}



template <class T>
int Tree<T>::size() const {
    // Start the recursion using the root as the first node
    return size(root);
}

template <class T>
int Tree<T>::size(shared_ptr<Node<T>> node) const{

    // If the node we're on is null, return the tree as size 0
    if (node == nullptr) return 0;

    // Keep track of our size
    int totalSize = 0;

    shared_ptr<Node<T>> left = node->left;
    shared_ptr<Node<T>> right = node->right;

    // Add the sizes of both sides of the tree
    if (left != nullptr) totalSize += size(left);
    if (right != nullptr) totalSize += size(right);

    // Include this node
    totalSize += 1;

    // Return the total size of this recursion
    return totalSize;
}

template <class T>
void Tree<T>::clear(){
    // Initialize the recursive deletion
    root = nullptr;
}
