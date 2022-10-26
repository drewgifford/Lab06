#include "Tree.h"
#include <vector>
#include <gtest/gtest.h>

using namespace std;

TEST(Tree, Insert1){
    Tree<int> bst;

    bst.insert(5);
    bst.insert(3);
    bst.insert(2);

    int size = bst.size();

    ASSERT_EQ(size, 3);

}
TEST(Tree, Insert2){
    Tree<int> bst;
    bst.insert(1);
    bst.insert(2);
    bst.insert(-1);
    bst.insert(5);

    int size = bst.size();

    ASSERT_EQ(size, 4);
}

TEST(Tree, Find1){
    Tree<int> bst;
    bst.insert(1);
    bst.insert(2);
    bst.insert(3);

    ASSERT_NE(bst.find(1), nullptr);
}
TEST(Tree, Find2){
    Tree<int> bst;
    bst.insert(1);
    bst.insert(7);
    bst.insert(3);
    bst.insert(-16);

    ASSERT_EQ(bst.find(69), nullptr);
}

TEST(Tree, Size1){
    Tree<int> bst;

    bst.insert(1);
    bst.insert(2);

    ASSERT_EQ(bst.size(), 2);
}
TEST(Tree, Size2){
    Tree<int> bst;

    bst.insert(69);
    bst.insert(-420);
    bst.insert(69420);

    ASSERT_EQ(bst.size(), 3);
}

TEST(Tree, Clear1){

    Tree<int> bst;
    bst.insert(5);
    bst.insert(4);
    bst.insert(0);

    bst.clear();

    ASSERT_EQ(bst.size(), 0);

}
TEST(Tree, Clear2){

    Tree<int> bst;
    bst.insert(9);
    bst.insert(4);
    bst.clear();
    bst.insert(0);

    ASSERT_EQ(bst.size(), 1);

}

TEST(Tree, GetAllAscending1){
    Tree<int> bst;
    bst.insert(5);
    bst.insert(6);
    bst.insert(3);

    vector<int> values = {3, 5, 6};

    ASSERT_EQ(bst.getAllAscending(), values);
}
TEST(Tree, GetAllAscending2){
    Tree<int> bst;
    bst.insert(9);
    bst.insert(12);
    bst.insert(6969);
    bst.clear();
    bst.insert(5);
    bst.insert(3000);
    bst.insert(-1);
    bst.insert(2);

    vector<int> values = {-1, 2, 5, 3000};

    ASSERT_EQ(bst.getAllAscending(), values);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}