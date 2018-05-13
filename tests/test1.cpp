#include "catch.hpp"
#include <TUI.hpp>
#include <BSTree.hpp>
#include <string>
#include <iostream>
#include <fstream>

TEST_CASE("Creating binary search tree") {
    BSTree::Tree tree1;
    REQUIRE(tree1.print_tree() == -1);
}

TEST_CASE("Testing orders output") {
    std::string direct = "8 3 1 6 4 7 10 14 13 ";
    std::string symmetric = "1 3 4 6 7 8 10 13 14 ";
    std::string reverse = "1 4 7 6 3 13 14 10 8 ";

    BSTree::Tree tree1{8, 10, 14, 13, 3, 1, 6, 4, 7};

    std::string buffer;
    std::stringstream out(buffer);
    REQUIRE(tree1.print_nodes(BSTree::Tree::order::direct, out) == 0);
    out << std::endl;
    REQUIRE(tree1.print_nodes(BSTree::Tree::order::symmetric, out) == 0);
    out << std::endl;    
    REQUIRE(tree1.print_nodes(BSTree::Tree::order::reverse, out) == 0);
    out << std::endl;

    std::string result;
    getline(out, result);
    REQUIRE(result==direct);
    getline(out, result);
    REQUIRE(result==symmetric);
    getline(out, result);
    REQUIRE(result==reverse);
}

TEST_CASE("Testing insert") {
    BSTree::Tree tree1{8, 10, 14, 13, 3, 1};
    tree1.insert(6);
    tree1.insert(4);
    tree1.insert(7);

    std::string direct = "8 3 1 6 4 7 10 14 13 ";
    std::string buffer;
    std::stringstream out(buffer);
    REQUIRE(tree1.print_nodes(BSTree::Tree::order::direct, out) == 0);
   
    std::string result;
    getline(out, result);
    REQUIRE(result==direct);
}

TEST_CASE("Testing remove") {
    BSTree::Tree tree{8, 10, 14, 13, 3, 1, 6, 4, 7};
    tree.remove(14);
    tree.remove(1);

    std::string expected = "8 3 6 4 7 10 13 ";
    std::string buffer;
    std::stringstream out(buffer);
    REQUIRE(tree.print_nodes(BSTree::Tree::order::direct, out) == 0);
    std::string result;
    getline(out, result);
    REQUIRE(result==expected);
}

TEST_CASE("Testing existing") {
    BSTree::Tree tree{8, 10, 14, 13, 3, 1, 6, 4, 7};
    REQUIRE(tree.exists(6) == true);
    REQUIRE(tree.exists(50) == false);
}

TEST_CASE("Testing input/output from file") {
    std::ofstream out("testInput.txt", std::ios::in);
    out << "Да";
    out.close();
    freopen("testInput.txt", "r", stdin);

    BSTree::Tree tree1{8, 10, 14, 13, 3, 1, 6, 4, 7};
    tree1.save("tree1.txt");

    BSTree::Tree tree2;
    tree2.load("tree1.txt");

    std::string buffer;
    std::stringstream str(buffer);
    str << tree1;
    str << std::endl;
    str << tree2;

    std::string result1, result2;
    getline(str, result1);
    getline(str, result2);

    REQUIRE(result1 == result2);
}