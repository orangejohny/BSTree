// header file for BSTree class

#include <string>
#include <vector>
#include <iostream>

namespace BSTree {
struct Node {
    int key;
    Node *left;
    Node *right;
    Node(int val) : key{val}, left{nullptr}, right{nullptr} {};
    Node(Node *origin) : key{origin->key}, left{origin->left}, right{origin->right} {};
};

class Tree {
private:
    Node *root;
    auto clean(Node* node) -> void {
        //обратный обход для удаления
        if (node == nullptr) return;
        clean(node->left);
        clean(node->right);
        delete node;
        node = nullptr;
    };
    
    auto _insert(Node* node, int val) -> Node*;
    auto direct_order(Node* node, std::ostream& out = std::cout) -> void;
    auto symmetric_order(Node* node, std::ostream& out = std::cout) -> void;
    auto reverse_order(Node* node, std::ostream& out = std::cout) -> void;
    auto my_order(Node* node, int lvl) -> void;

public:
    
    enum class order {
        direct,
        symmetric,
        reverse
    };

    Tree() : root{nullptr} {};
    Tree(std::initializer_list<int> list);
    Tree(std::vector<int> list);    
    Tree(const Tree &tree);						//конструктор копирования (при начальной инициализации)
    auto operator=(const Tree &tree) -> Tree &; //оператор присваивания
    auto insert(int val) -> bool;
    auto exists(int val) -> bool;
    auto remove(int val) -> bool;
    auto save(const std::string& path) -> bool;
    auto load(const std::string& path) -> bool;
    auto find(int val) -> bool;
    auto print_tree() -> int;
    auto print_nodes(order ord, std::ostream& out = std::cout) -> int {
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
    ~Tree() {
        clean(root);
    };
};
}