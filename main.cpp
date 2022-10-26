#include "Tree.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;
int main(){

    Tree<string> bst;

    bst.insert("Star Trek");
    bst.insert("Star Wars");
    bst.insert("Space Balls");
    bst.insert("Galaxy Quest");

    int size = bst.size();

    cout << "Size: " << size << endl;


    vector<string> values = bst.getAllAscending();

    for (int i = 0; i < values.size(); i++){
        cout << values.at(i) << ", ";
    }
    cout << endl;
    
    return 0;
}