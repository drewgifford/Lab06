#include "Tree.h"
#include <string>


using namespace std;
int main(){

    Tree<string> bst;

    bst.insert("Star Wars");
    bst.insert("Star Trek");
    bst.insert("Space Balls");
    bst.insert("Galaxy Quest");



    return 0;
}