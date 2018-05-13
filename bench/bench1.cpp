#include "catch.hpp"
#include <TUI.hpp>
#include <BSTree.hpp>
#include <ctime>
#include <fstream>
#include <iostream>

TEST_CASE("MY_BENCH") {
    freopen("output.txt", "w", stdout);
    std::ofstream out_("BenchInput.txt", std::ios::in);
    out_ << "Да\nДа\nДа\nДа\nДа\nДа\nДа\nДа\nДа\nДа\nДа\nДа\nДа\nДа\n";
    out_.close();
    freopen("BenchInput.txt", "r", stdin);
    std::ofstream out("out.txt", std::ios::out);    

    for (int expo = 1; expo <= 7; expo++) {
        out << "\n**10^**" << expo << std::endl << std::endl;
        BSTree::Tree tree;
        clock_t t;
        int value;
        for (int i = 0; i < pow(10, expo); i++) {
            t = clock();
            value = rand();
            tree.insert(value);
            t = clock() - t;
        }

        out << "```java\nINSERT for 10^" << expo << " elements takes " << ((double)t)/CLOCKS_PER_SEC << " seconds" << std::endl;

        t = clock();
        tree.exists(value);
        t = clock() - t;
        out << "EXISTS for 10^" << expo << " elements takes " << ((double)t)/CLOCKS_PER_SEC << " seconds" << std::endl; 

        t = clock();
        tree.print_tree();
        t = clock() - t;
        out << "PRINT_TREE for 10^" << expo << " elements takes " << ((double)t)/CLOCKS_PER_SEC << " seconds" << std::endl;

        t = clock();
        tree.print_nodes(BSTree::Tree::order::direct);
        t = clock() - t;
        out << "PRINT_NODES for 10^" << expo << " elements takes " << ((double)t)/CLOCKS_PER_SEC << " seconds" << std::endl; 

        t = clock();
        tree.remove(value);
        t = clock() - t;
        out << "REMOVE for 10^" << expo << " elements takes " << ((double)t)/CLOCKS_PER_SEC << " seconds" << std::endl;

        t = clock();
        tree.save("tree.txt");
        t = clock() - t;
        out << "SAVE for 10^" << expo << " elements takes " << ((double)t)/CLOCKS_PER_SEC << " seconds" << std::endl;

        t = clock();
        tree.load("tree.txt");
        t = clock() - t;
        out << "LOAD for 10^" << expo << " elements takes " << ((double)t)/CLOCKS_PER_SEC << " seconds\n```" << std::endl;    
    }
}

/*
TEST_CASE("10e1") {
    int exp = 1;

    BSTree::Tree tree;
    Catch::BenchmarkLooper looper("name");

    for (int i = 0; i < exp; i++) {
        looper.needsMoreIterations();    
    }

    for (looper; looper; looper.increment()) {
        tree.insert(rand());
    }

    
}

TEST_CASE("Inserting 10e2") {
    int exp = 2;

    BSTree::Tree tree;
    Catch::BenchmarkLooper looper("name");

    for (int i = 0; i < exp; i++) {
        looper.needsMoreIterations();    
    }

    for (looper; looper; looper.increment()) {
        tree.insert(rand());
    }
}

TEST_CASE("Inserting 10e3") {
    int exp = 3;

    BSTree::Tree tree;
    Catch::BenchmarkLooper looper("name");

    for (int i = 0; i < exp; i++) {
        looper.needsMoreIterations();    
    }

    for (looper; looper; looper.increment()) {
        tree.insert(rand());
    }
}

TEST_CASE("Inserting 10e4") {
    int exp = 4;

    BSTree::Tree tree;
    Catch::BenchmarkLooper looper("name");

    for (int i = 0; i < exp; i++) {
        looper.needsMoreIterations();    
    }

    for (looper; looper; looper.increment()) {
        tree.insert(rand());
    }
}

TEST_CASE("Inserting 10e5") {
    int exp = 5;

    BSTree::Tree tree;
    Catch::BenchmarkLooper looper("name");

    for (int i = 0; i < exp; i++) {
        looper.needsMoreIterations();    
    }

    for (looper; looper; looper.increment()) {
        tree.insert(rand());
    }
}

TEST_CASE("Inserting 10e6") {
    int exp = 6;

    BSTree::Tree tree;
    Catch::BenchmarkLooper looper("name");

    for (int i = 0; i < exp; i++) {
        looper.needsMoreIterations();    
    }

    for (looper; looper; looper.increment()) {
        tree.insert(rand());
    }
}
*/
