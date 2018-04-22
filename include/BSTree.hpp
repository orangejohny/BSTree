// header file for BSTree class

#include <string>
#include <vector>

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
    void clean(Node* node) {
        //обратный обход для удаления
        if (node == nullptr) return;
        clean(node->left);
        clean(node->right);
        delete node;
        node = nullptr;
    };
    
    Node* _insert(Node* node, int val);
    void direct_order(Node* node);
    void symmetric_order(Node* node);
    void reverse_order(Node* node);
    void my_order(Node* node, int lvl);

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
    bool insert(int val);
    bool exists(int val);
    bool remove(int val);
    bool save(const std::string& path);
    bool load(const std::string& path);
    bool find(int val);
    int print_tree();
    int print_nodes(order ord) {
        if (root == nullptr) {
            return -1;
        }
        switch (ord) {
        case order::direct:
            direct_order(root);
            break;
        case order::symmetric:
            symmetric_order(root);
            break;
        case order::reverse:
            reverse_order(root);
        };

        return 0;
    }
    ~Tree() {
        clean(root);
    };
};
}