// example that demonstrates creation of BSTree,
// output using different colors, inserting elements


#include <BSTree.hpp>
#include <TUI.hpp>
#include <iostream>
int main() {
    BSTree::Tree<int> tree{6, 8, 7, 9, 4, 1};
    TUI::print_confirm("BSTree of sequence 6 8 7 9 4 1 was created");

    TUI::print_ln("BSTree is:");
    tree.print_tree();

    tree.insert(3);
    tree.insert(2);
    TUI::print_confirm("3 and 2 inserted:");
    tree.print_tree();

    BSTree::Tree<int> _tree{};
    TUI::print_ln("Trying to print empty BSTree:");
    if (_tree.print_tree()==-1) {
        TUI::print_error("BSTree is empty!");
    }
    TUI::user_exit();
}