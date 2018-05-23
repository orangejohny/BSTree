// example that demonstrates deletin of the node

#include <BSTree.hpp>
#include <TUI.hpp>

int main() {
    BSTree::Tree<int> tree{8, 10, 14, 13, 3, 1, 6, 4, 7};
    TUI::print_confirm("BSTree of sequence 8 10 14 13 3 1 6 4 7");
    tree.print_tree();

    tree.remove(14);
    TUI::print_confirm("\n14 was removed\n");
    tree.print_tree();

    tree.remove(6);
    TUI::print_confirm("6 was removed\n");
    tree.print_tree();

    TUI::user_exit();    
}