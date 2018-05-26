// usage of iterator

#include <BSTree.hpp>
#include <iostream>

using BSTree::Tree;
using BSTree::bIt;
using std::cout;
using std::endl;

int main() {
    Tree<int> tree{8, 10, 14, 13, 3, 1, 6, 4, 7};
    cout << "Tree is:\n";
    tree.print_nodes(Tree<int>::order::symmetric);
    
    cout << "\nUsing iterator to print keys\n";
    for (int c : tree) {
        std::cout << c << " ";
    }

    cout << "\nUsing iterator to print keys in reverse order\n";
    bIt<int> it = tree.rbegin();
    for (; it != tree.rend(); --it) {
        std::cout << *it << " ";
    }
}