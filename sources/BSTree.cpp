// source file for Tree class
#include <BSTree.hpp>

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

auto BSTree::Tree::insert(int val) -> bool {
    Node* result =_insert(root, val);
    if (result == nullptr) {
        return false;
    } else {
        root = result;
        return true;
    }
}

auto BSTree::Tree::_insert(Node* node, int val) -> Node* {
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

auto BSTree::Tree::print_tree() -> int {
    if (root == nullptr) {
        return -1;
    }
    my_order(root, 0);
    return 0;
}

auto BSTree::Tree::my_order(Node* node, int lvl) -> void {
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

auto BSTree::Tree::direct_order(Node* node, std::ostream& out) -> void {
    if (node != nullptr) {
        direct_order(node->left, out);
        out << node->key << " ";
        direct_order(node->right, out);
    }
}

auto BSTree::Tree::symmetric_order(Node* node, std::ostream& out) -> void {
    if (node != nullptr) {
        out << node->key << " ";
        symmetric_order(node->left, out);
        symmetric_order(node->right, out);
    }
}

auto BSTree::Tree::reverse_order(Node* node, std::ostream& out) -> void{
    if (node != nullptr) {
        reverse_order(node->left, out);
        reverse_order(node->right, out);
        out << node->key << " ";        
    }
}