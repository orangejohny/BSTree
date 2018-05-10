// source file for Tree class
#include <BSTree.hpp>


// Constructor
BSTree::Tree::Tree(std::initializer_list<int> list) {
    root = nullptr;
    for (int ch : list) {
        this->insert(ch);
    }
}

// Constructor
BSTree::Tree::Tree(std::vector<int> list) {
    root = nullptr;
    for (int ch : list) {
        this->insert(ch);
    }
}

// Constructor
BSTree::Tree::Tree(const Tree &tree) {
    root = nullptr;

    std::string buffer;
    std::stringstream out(buffer);
    direct_order(tree.root, out);

    std::string ch;
    while(out) {
        out >> ch;
        insert(std::stoi(ch));
    }
}

// Public function for inserting elements
auto BSTree::Tree::insert(int val) -> bool {
    bool is_inserted = true;    
    Node* result =_insert(root, val, is_inserted);
    root = result;
    return is_inserted;
}

// Private utility function for inserting elements
auto BSTree::Tree::_insert(Node* node, int val, bool& is_inserted) -> Node* {
    if (node == nullptr) {
        return new Node(val);
    } else if (val < node->key) {
        node->left = _insert(node->left, val, is_inserted);
    } else if (val > node->key) {
        node->right = _insert(node->right, val, is_inserted);
    } else {
        is_inserted=false;
        return node;
    }
}

// Print nodes in visual form
auto BSTree::Tree::print_tree() const -> int {
    if (root == nullptr) {
        return -1;
    }
    my_order(root, 0);
    return 0;
}

// Private utility function for printing nodes
auto BSTree::Tree::my_order(Node* node, int lvl) const -> void {
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
auto BSTree::Tree::direct_order(Node* node, std::ostream& out) const -> void {
    if (node != nullptr) {
        direct_order(node->left, out);
        out << node->key << " ";
        direct_order(node->right, out);
    }
}

// Private function that prints nodes in symmetric order
auto BSTree::Tree::symmetric_order(Node* node, std::ostream& out) const -> void {
    if (node != nullptr) {
        out << node->key << " ";
        symmetric_order(node->left, out);
        symmetric_order(node->right, out);
    }
}

// Private function that prints nodes in reverse order
auto BSTree::Tree::reverse_order(Node* node, std::ostream& out) const -> void{
    if (node != nullptr) {
        reverse_order(node->left, out);
        reverse_order(node->right, out);
        out << node->key << " ";        
    }
}

// Public function for deleting node with particular value
auto BSTree::Tree::remove(int val) -> bool {
    bool is_deleted = false;
    root =_remove(root, val, is_deleted);
    return is_deleted;
}

// Private utility function for deleting node
auto BSTree::Tree::_remove(Node* node, int val, bool& is_deleted) -> Node* {
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
auto BSTree::Tree::min_elem(Node* node) const -> Node* {
    if (node->left == nullptr) {
        return node;
    }
    return min_elem(node->left);
}

// Function that saves BSTree to the file
auto BSTree::Tree::save(const std::string& path) const -> bool {
    std::ifstream fin(path);
    if (!fin.is_open()) {
        std::ofstream fout(path);
        direct_order(root, fout);
        fout.close();
        return true;
    } else {
        std::string answer;
        std::cout << "Перезаписать файл? (Да|Нет)" << std::endl;
        std::cin >> answer;
        if (answer == "Да" || answer == "ДА" || answer == "да") {
            std::ofstream fout(path);
            direct_order(root, fout);
            fout.close();
            return true;
        } else {
            return false;
        }
    }
}

// Function that loads BSTree from the file
auto BSTree::Tree::load(const std::string& path) -> bool {
    std::ifstream fin(path);
    if (!fin.is_open()) {
        return false;
    }

    Tree tmp;
    swap(tmp);

    std::string ch;
    while(fin) {
        fin >> ch;
        insert(std::stoi(ch));
    }

    fin.close();
    return true;
}

// Overloading of =
auto BSTree::Tree::operator=(const Tree &tree)-> void {
    Tree tmp{tree};
    swap(tmp);
}

// Check if node is in tree
auto BSTree::Tree::exists(int val) const -> bool {
    bool is_exist = false;
    _exists(root, val, is_exist);
    return is_exist;
}

// Private utility function for checking
auto BSTree::Tree::_exists(Node* node, int val, bool& is_exist) const -> void {
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