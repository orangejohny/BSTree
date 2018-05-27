#include "catch.hpp"
#include <BSTree.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <iterator.hpp>

TEST_CASE("Creating binary search tree and output") {
    BSTree::Tree<int> tree1;
    REQUIRE(tree1.print_tree() == -1);
    REQUIRE(tree1.print_nodes(BSTree::Tree<int>::order::direct) == -1);
    REQUIRE(tree1.remove(1) == false);
}

TEST_CASE("Testing orders output") {
    std::string direct = "8 3 1 6 4 7 10 14 13 ";
    std::string symmetric = "1 3 4 6 7 8 10 13 14 ";
    std::string reverse = "1 4 7 6 3 13 14 10 8 ";

    BSTree::Tree<int> tree1{8, 10, 14, 13, 3, 1, 6, 4, 7};

    std::string buffer;
    std::stringstream out(buffer);
    REQUIRE(tree1.print_nodes(BSTree::Tree<int>::order::direct, out) == 0);
    out << std::endl;
    REQUIRE(tree1.print_nodes(BSTree::Tree<int>::order::symmetric, out) == 0);
    out << std::endl;    
    REQUIRE(tree1.print_nodes(BSTree::Tree<int>::order::reverse, out) == 0);
    out << std::endl;

    std::string result;
    getline(out, result);
    REQUIRE(result==direct);
    getline(out, result);
    REQUIRE(result==symmetric);
    getline(out, result);
    REQUIRE(result==reverse);

    REQUIRE(tree1.print_tree(out) == 0);
    
}

TEST_CASE("Testing insert") {
    BSTree::Tree<int> tree1{8, 10, 14, 13, 3, 1};
    tree1.insert(6);
    tree1.insert(4);
    tree1.insert(7);

    std::string direct = "8 3 1 6 4 7 10 14 13 ";
    std::string buffer;
    std::stringstream out(buffer);
    REQUIRE(tree1.print_nodes(BSTree::Tree<int>::order::direct, out) == 0);
   
    std::string result;
    getline(out, result);
    REQUIRE(result==direct);
}

TEST_CASE("Testing remove") {
    BSTree::Tree<int> tree{8, 10, 14, 13, 3, 1, 6, 4, 7};
    tree.remove(3);
    tree.remove(14);
    tree.remove(1);
    tree.remove(6);
    tree.remove(8);
    tree.remove(10);

    std::string expected = "4 7 13 ";
    std::string buffer;
    std::stringstream out(buffer);
    REQUIRE(tree.print_nodes(BSTree::Tree<int>::order::symmetric, out) == 0);
    std::string result;
    getline(out, result);
    REQUIRE(result==expected);
}

TEST_CASE("Testing existing") {
    BSTree::Tree<int> tree{8, 10, 14, 13, 3, 1, 6, 4, 7};
    REQUIRE(tree.exists(6) == true);
    REQUIRE(tree.exists(50) == false);
}

TEST_CASE("Testing input/output from file") {
    std::ofstream out("testInput.txt", std::ios::out);
    std::ifstream inp("tree1.txt");
    if (inp.is_open()) out << "Да\n";
    inp.close();
    out << "Да\nНет\n";
    out.close();
    freopen("testInput.txt", "r", stdin);

    BSTree::Tree<int> tree1{8, 10, 1, 6, 4, 7};
    BSTree::Tree<int> tree22{8, 10, 14, 13, 3, 1, 6, 4, 7};
    BSTree::Tree<int> tree3{8, 4, 13, 3, 1, 7};
    
    REQUIRE(tree1.save("tree1.txt") == true);
    REQUIRE(tree22.save("tree1.txt") == true);
    REQUIRE(tree3.save("tree1.txt") == false);

    BSTree::Tree<int> tree2;
    tree2.load("tree1.txt");

    REQUIRE(tree2.load("aaaa.txt") == false);

    std::string buffer;
    std::stringstream str(buffer);
    str << tree22;
    str << std::endl;
    str << tree2;

    std::string result1, result2;
    getline(str, result1);
    getline(str, result2);

    REQUIRE(result1 == result2);
}

TEST_CASE("Validation") {
    BSTree::Tree<int> tree{5, 7, 9, 4, 2, 3, 4, 9};
    REQUIRE(tree.validate() == true);
}

TEST_CASE("Assigment of tree") {
    BSTree::Tree<int> tree1 {1, 2, 3, 4};
    BSTree::Tree<int> tree2 {1, 2, 3};
    tree1 = tree2;

    std::string buffer;
    std::stringstream out(buffer);

    out << tree1 << std::endl << tree2;

    std::string t1, t2;
    getline(out, t1);
    getline(out, t2);

    REQUIRE(t1 == t2);
}

TEST_CASE("Testing of iterator") {
    BSTree::Tree<int> tree{8, 10, 14, 13, 3, 1, 6, 4, 7};
    std::string buffer;
    std::stringstream out(buffer);
    
    tree.print_nodes(BSTree::Tree<int>::order::symmetric, out);
    out << std::endl;

    for (int c : tree) {
        out << c << " ";
    }
    out << std::endl;

    BSTree::bIt<int> it = tree.rbegin();
    for (; it != tree.rend(); --it) {
        out << *it << " ";
    }
    out << std::endl;
    
    std::string s1,s2,r1,r2;
    getline(out, s1);
    getline(out, s2);
    getline(out, r1);
    r2 = "14 13 10 8 7 6 4 3 1 ";       

    REQUIRE(s1 == s2);
    REQUIRE(r1 == r2);
}