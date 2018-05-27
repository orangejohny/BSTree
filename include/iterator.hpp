#include <node.hpp>
#include <iterator>

#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

namespace BSTree {
template<typename type>
class bIt : public std::iterator<std::bidirectional_iterator_tag, Node<type>> {
private:
    Node<type>* ptr;
    Node<type>* next(Node<type>* node);
    Node<type>* prev(Node<type>* node);
    auto min_elem(Node<type>* node) const -> Node<type>*;
    auto max_elem(Node<type>* node) const -> Node<type>*; 
public:
    bIt(Node<type>* p) : ptr{p} {};
    bIt(const bIt<type>& other) : ptr{other.ptr} {};
    bIt<type>& operator=(const bIt<type>& other);
    bIt<type>& operator++();
    bIt<type> operator++(int);
    bIt<type>& operator--();
    bIt<type> operator--(int);
    bool operator==(const bIt<type>& other) const;
    bool operator!=(const bIt<type>& other) const;
    type& operator*() const;
    //type* operator->() const;

};

template<typename type>
auto bIt<type>::min_elem(Node<type>* node) const -> Node<type>* {
    if (node->left == nullptr) {
        return node;
    }
    return min_elem(node->left);
}

template<typename type>
auto bIt<type>::max_elem(Node<type>* node) const -> Node<type>* {
    if (node->right == nullptr) {
        return node;
    }
    return max_elem(node->right);
}

template<typename type>
Node<type>* bIt<type>::next(Node<type>* node) {
    if (node->right != nullptr) {
        return min_elem(node->right);
    }
    Node<type>* par = node->parent;
    while (par != nullptr && node == par->right) {
        node = par;
        par = par->parent;
    }
    return par;
}

template<typename type>
Node<type>* bIt<type>::prev(Node<type>* node) {
    if (node->left != nullptr) {
        return max_elem(node->left);
    }
    Node<type>* par = node->parent;
    while (par != nullptr && node == par->left) {
        node = par;
        par = par->parent;
    }
    return par;
}

template<typename type>
bIt<type>& bIt<type>::operator=(const bIt<type>& other) {
    ptr = other.ptr;
}

template<typename type>
bIt<type>& bIt<type>::operator++() {
    ptr = next(ptr);
    return *this;
}

template<typename type>
bIt<type> bIt<type>::operator++(int) {
    bIt<type> tmp(*this);
    ++(*this);  
    return tmp;
}

template<typename type>
bIt<type>& bIt<type>::operator--() {
    ptr = prev(ptr);
    return *this;
}

template<typename type>
bIt<type> bIt<type>::operator--(int) {
    bIt<type> tmp(*this);
    --(*this);  
    return tmp;
}

template<typename type>
bool bIt<type>::operator==(const bIt<type>& other) const {
    return ptr == other.ptr;
}

template<typename type>
bool bIt<type>::operator!=(const bIt<type>& other) const {
    return ptr != other.ptr;
}

template<typename type>
type& bIt<type>::operator*() const {
    return ptr->key;
}

/*
template<typename type>
type* bIt<type>::operator->() const {
    return &(ptr->key);
}
*/
}

#endif