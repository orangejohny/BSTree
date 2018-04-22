// source file for Tree class
#include "BSTree.hpp"
#include <iostream>

using namespace BSTree;

BSTree::Tree::Tree(std::initializer_list<int> list) {
    root = nullptr;
    for (int ch : list) {
        this->insert(ch);
    }
}

BSTree::Tree::Tree(std::vector<int> list) {
    root = nullptr;
    for (int ch : list) {
        this->insert(ch);
    }
}

bool BSTree::Tree::insert(int val) {
    Node* result =_insert(root, val);
    if (result == nullptr) {
        return false;
    } else {
        root = result;
        return true;
    }
}

Node* BSTree::Tree::_insert(Node* node, int val) {
    if (node == nullptr) {
        return new Node(val);
    } else if (val < node->key) {
        node->left = _insert(node->left, val);
    } else if (val > node->key) {
        node->right = _insert(node->right, val);
    } else {
        return node;
    }
}

int BSTree::Tree::print_tree() {
    if (root == nullptr) {
        return -1;
    }
    my_order(root, 0);
    return 0;
}

void BSTree::Tree::my_order(Node* node, int lvl) {
    if (node != nullptr) {
        my_order(node->right, lvl+1);
        for (int i = 0; i < lvl; i++) {
            if (lvl != 1) {
                std::cout << "     ";
            } else {
                std::cout << "    ";
            }
        }
        if (lvl != 0) std::cout << "--";
        std::cout.width(4);                
        std::cout << std::left << node->key << std::endl;
        my_order(node->left, lvl+1);
    }
}

void BSTree::Tree::direct_order(Node* node) {
    if (node != nullptr) {
        direct_order(node->left);
        std::cout << node->key << " ";
        direct_order(node->right);
    }
}

void BSTree::Tree::symmetric_order(Node* node) {
    if (node != nullptr) {
        std::cout << node->key << " ";
        symmetric_order(node->left);
        symmetric_order(node->right);
    }
}

void BSTree::Tree::reverse_order(Node* node) {
    if (node != nullptr) {
        symmetric_order(node->left);
        symmetric_order(node->right);
        std::cout << node->key << " ";        
    }
}