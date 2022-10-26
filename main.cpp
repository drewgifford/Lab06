#include "Tree.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;
int main(){

    Tree<string> bst;

    bst.insert("Halloween");
    bst.insert("A Nightmare on Elm Street");
    bst.insert("Hocus Pocus");
    bst.insert("Beetlejuice");

    int size = bst.size();

    cout << "GetAllAscending: " << size << endl;


    vector<string> values = bst.getAllAscending();

    for (int i = 0; i < values.size(); i++){
        cout << values.at(i) << ", ";
    }
    cout << endl;
    
    return 0;
}