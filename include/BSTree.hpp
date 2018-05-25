// header file for BSTree class

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <iterator>

namespace BSTree {
template<typename type>
struct Node {
    type key;
    Node<type> *left;
    Node<type> *right;
    Node<type>(type val) : key{val}, left{nullptr}, right{nullptr} {};
    Node<type>(Node<type> *origin) : key{origin->key}, left{origin->left}, right{origin->right} {};
};

template<typename type>
class Tree {
private:
    Node<type> *root;
    auto clean(Node<type>* node) -> void { // Utility function for destructor
        if (node == nullptr) return;
        clean(node->left);
        clean(node->right);
        delete node;
        node = nullptr;
    };
    
    auto check(Node<type>* node, type min, type max) -> bool;
    auto _insert(Node<type>* node, type val, bool&) -> void;
    auto direct_order(Node<type>* node, std::ostream& out = std::cout) const -> void;
    auto symmetric_order(Node<type>* node, std::ostream& out = std::cout) const -> void;
    auto reverse_order(Node<type>* node, std::ostream& out = std::cout) const -> void;
    auto my_order(Node<type>* node, int lvl) const -> void;
    auto _remove(Node<type>* node, type val, bool&) -> Node<type>*;
    auto min_elem(Node<type>* node) const -> Node<type>*;
    auto swap(Tree<type>& t) -> void {
        std::swap(root, t.root);
    }
    auto _exists(Node<type>* node, type val, bool&) const -> void;

public:
    
    enum class order {
        direct,
        symmetric,
        reverse
    };

    Tree() : root{nullptr} {};
    Tree(std::initializer_list<type> list);
    Tree(std::vector<type> list);    
    Tree(const Tree<type> &tree);
    auto operator=(const Tree<type> &tree) -> void;
    auto insert(type val) -> bool;
    auto exists(type val) const -> bool;
    auto remove(type val) -> bool;
    auto save(const std::string& path) const -> bool;
    auto load(const std::string& path) -> bool;
    auto print_tree() const -> int;
    auto print_nodes(order ord, std::ostream& out = std::cout) const -> int {
        if (root == nullptr) {
            return -1;
        }
        switch (ord) {
        case order::direct:
            direct_order(root, out);
            break;
        case order::symmetric:
            symmetric_order(root, out);
            break;
        case order::reverse:
            reverse_order(root, out);
        };

        return 0;
    }

    // Overloading of <<
    friend auto operator<<(std::ostream& stream, const Tree<type>& tree) -> std::ostream& {
        tree.print_nodes(Tree<type>::order::direct, stream);
        return stream;
    }

    // Overloading of >>. Adds to tree elements from one line
    friend auto operator>>(std::istream& stream, Tree<type>& tree) -> std::istream& {
        std::string buffer;
        getline(stream, buffer);
        std::istringstream in(buffer);
        type ch;
        while(in) {
            in >> ch;
            tree.insert(ch);
        }
        return stream;
    }

    auto validate() -> bool;
    auto begin() -> iterator {
        return iterator(root);
    }
    auto end() -> iterator {
        return iterator(min_elem(root));
    }

    ~Tree() {
        clean(root);
    }
};

template<typename type>
class it : public std::iterator<std::bidirectional_iterator_tag, type> {
protected:
    type ptr;
public:
    it(type p) : ptr{p} {};
    it(const it<type>& other) : ptr{other.ptr} {};
};
}


// Constructor
template<typename type>
BSTree::Tree<type>::Tree(std::initializer_list<type> list) {
    root = nullptr;
    for (type ch : list) {
        this->insert(ch);
    }
}

// Constructor
template<typename type>
BSTree::Tree<type>::Tree(std::vector<type> list) {
    root = nullptr;
    for (type ch : list) {
        this->insert(ch);
    }
}

// Constructor
template<typename type>
BSTree::Tree<type>::Tree(const Tree &tree) {
    root = nullptr;

    std::string buffer;
    std::stringstream out(buffer);
    out << tree;
    out >> *this;
}

// Public function for inserting elements
template<typename type>
auto BSTree::Tree<type>::insert(type val) -> bool {
    if (root == nullptr) {
        root = new Node<type>(val);
        return true;
    } else {
        bool is_inserted = false;        
        _insert(root, val, is_inserted);
        return is_inserted;
    }
}

// Private utility function for inserting elements
template<typename type>
auto BSTree::Tree<type>::_insert(Node<type>* node, type val, bool& is_inserted) -> void {
    if (val < node->key) {
        if (node->left == nullptr) {
            node->left = new Node<type>(val);
            is_inserted = true;
        } else {
            _insert(node->left, val, is_inserted);  
        }
    } else if (val > node->key) {
        if (node->right == nullptr) {
            node->right = new Node<type>(val);
            is_inserted = true;
        } else {
            _insert(node->right, val, is_inserted);  
        }
    }
}

// Print nodes in visual form
template<typename type>
auto BSTree::Tree<type>::print_tree() const -> int {
    if (root == nullptr) {
        return -1;
    }
    my_order(root, 0);
    return 0;
}

// Private utility function for printing nodes
template<typename type>
auto BSTree::Tree<type>::my_order(Node<type>* node, int lvl) const -> void {
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

// Private function that prints nodes in direct order
template<typename type>
auto BSTree::Tree<type>::direct_order(Node<type>* node, std::ostream& out) const -> void {
    if (node != nullptr) {
        out << node->key << " ";
        direct_order(node->left, out);
        direct_order(node->right, out);
    }
}

// Private function that prints nodes in symmetric order
template<typename type>
auto BSTree::Tree<type>::symmetric_order(Node<type>* node, std::ostream& out) const -> void {
    if (node != nullptr) {
        symmetric_order(node->left, out);
        out << node->key << " ";
        symmetric_order(node->right, out);
    }
}

// Private function that prints nodes in reverse order
template<typename type>
auto BSTree::Tree<type>::reverse_order(Node<type>* node, std::ostream& out) const -> void{
    if (node != nullptr) {
        reverse_order(node->left, out);
        reverse_order(node->right, out);
        out << node->key << " ";        
    }
}

// Public function for deleting node with particular value
template<typename type>
auto BSTree::Tree<type>::remove(type val) -> bool {
    bool is_deleted = false;
    root =_remove(root, val, is_deleted);
    return is_deleted;
}

// Private utility function for deleting node
template<typename type>
auto BSTree::Tree<type>::_remove(Node<type>* node, type val, bool& is_deleted) -> Node<type>* {
    if (node == nullptr) {
        return node;
    }

    if (val < node->key) {
        node->left = _remove(node->left, val, is_deleted);
    } else if (val > node->key) {
        node->right = _remove(node->right, val, is_deleted);
    } else if (node->left != nullptr && node->right != nullptr) {
        is_deleted = true;
        node->key = min_elem(node->right)->key;
        node->right = _remove(node->right, node->key, is_deleted);
    } else {
        if (node->left != nullptr) {
            node = node->left;
        } else {
            node = node->right;
        }
        is_deleted = true;
    }
    return node;
}

// Private function that searchs min element
template<typename type>
auto BSTree::Tree<type>::min_elem(Node<type>* node) const -> Node<type>* {
    if (node->left == nullptr) {
        return node;
    }
    return min_elem(node->left);
}

// Function that saves BSTree to the file
template<typename type>
auto BSTree::Tree<type>::save(const std::string& path) const -> bool {
    std::ifstream fin(path);
    if (!fin.is_open()) {
        std::ofstream fout(path);
        fout << *this;
        fout.close();
        return true;
    } else {
        std::string answer;
        std::cout << "Перезаписать файл? (Да|Нет)" << std::endl;
        std::cin >> answer;
        if (answer == "Да" || answer == "ДА" || answer == "да") {
            std::ofstream fout(path);
            fout << *this;
            fout.close();
            return true;
        } else {
            return false;
        }
    }
}

// Function that loads BSTree from the file
template<typename type>
auto BSTree::Tree<type>::load(const std::string& path) -> bool {
    std::ifstream fin(path);
    if (!fin.is_open()) {
        return false;
    }

    Tree tmp;

    fin >> tmp;

    swap(tmp);
    return true;
}

// Overloading of =
template<typename type>
auto BSTree::Tree<type>::operator=(const Tree &tree)-> void {
    Tree{tree}.swap(*this);
}

// Check if node is in tree
template<typename type>
auto BSTree::Tree<type>::exists(type val) const -> bool {
    bool is_exist = false;
    _exists(root, val, is_exist);
    return is_exist;
}

// Private utility function for checking
template<typename type>
auto BSTree::Tree<type>::_exists(Node<type>* node, type val, bool& is_exist) const -> void {
    if (node == nullptr) {
        return;
    } else if (val < node->key) {
        _exists(node->left, val, is_exist);
    } else if (val > node->key) {
        _exists(node->right, val, is_exist);
    } else {
        is_exist=true;
        return;
    }
}

// Is it binary searh tree?
template<typename type>
auto BSTree::Tree<type>::validate() -> bool {
    return check(root, std::numeric_limits<type>::min(), std::numeric_limits<type>::max());
}

// Private utility function
template<typename type>
auto BSTree::Tree<type>::check(Node<type>* node, type min, type max) -> bool {
    if (node == nullptr) return true;
    if (node->key <= min || max <= node->key) return false; 
    return check(node->left, min, node->key) && check(node->right, node->key, max);
}