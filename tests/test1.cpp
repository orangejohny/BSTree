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
    std::string direct = "1 3 4 6 7 8 10 13 14 ";
    std::string symmetric = "8 3 1 6 4 7 10 14 13 ";
    std::string reverse = "1 4 7 6 3 13 14 10 8 ";

    BSTree::Tree tree1{8, 10, 14, 13, 3, 1, 6, 4, 7};

    //std::fstream out("test2.txt", std::ios_base::out | std::ios_base::in);
    std::string buffer;
    std::stringstream out(buffer);
    REQUIRE(tree1.print_nodes(BSTree::Tree::order::direct, out) == 0);
    out << std::endl;
    REQUIRE(tree1.print_nodes(BSTree::Tree::order::symmetric, out) == 0);
    out << std::endl;    
    REQUIRE(tree1.print_nodes(BSTree::Tree::order::reverse, out) == 0);
    out << std::endl;    
    //out.close();

    //std::ifstream in("test2.txt", std::ios_base::in);
    out.seekg(0);
    std::string result;
    getline(out, result);
    REQUIRE(result==direct);
    getline(out, result);
    REQUIRE(result==symmetric);
    getline(out, result);
    REQUIRE(result==reverse);
    //out.close();
}

TEST_CASE("Testing insert") {
    BSTree::Tree tree1{8, 10, 14, 13, 3, 1};
    tree1.insert(6);
    tree1.insert(4);
    tree1.insert(7);

    std::string direct = "1 3 4 6 7 8 10 13 14 ";
    //std::fstream out("test3.txt", std::ios_base::out | std::ios_base::in);
    std::string buffer;
    std::stringstream out(buffer);
    REQUIRE(tree1.print_nodes(BSTree::Tree::order::direct, out) == 0);
    //out.close();

    //std::ifstream in("test3.txt", std::ios_base::in);
    out.seekg(0);    
    std::string result;
    getline(out, result);
    REQUIRE(result==direct);
    //out.close();    
}