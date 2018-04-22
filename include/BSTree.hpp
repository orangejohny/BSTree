// header file for BSTree class

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
    void clean(Node *&node) {
        //обратный обход для удаления
        clean(node->left);
        clean(node->right);
        delete node;
        node = nullptr;
    };

public:
    enum class order {
        direct,
        symmetric,
        reverse
    };

    Tree() : root{nullptr} {};
    Tree(const Tree &tree);						//конструктор копирования (при начальной инициализации)
    auto operator=(const Tree &tree) -> Tree &; //оператор присваивания
    bool insert(int val);
    /*auto list(order ord) {
        switch (ord) {
        case order::direct:  //проверка на пустоту - node, data - left - right(рекурсия)
        case order::symmetric:
        case order::reverse:
        };
    }*/
    ~Tree() {
        clean(root);
    };
    bool remove(int val);
    bool find(int val);
};
}