#ifndef __NODE_HPP__
#define __NODE_HPP__

namespace BSTree {
template<typename type>
struct Node {
    type key;
    Node<type> *left;
    Node<type> *right;
    Node<type> *parent;
    Node<type>(type val) : key{val}, left{nullptr}, right{nullptr}, parent{nullptr} {};
    Node<type>(Node<type> *origin) : key{origin->key}, left{origin->left}, right{origin->right} {};
};
}

#endif