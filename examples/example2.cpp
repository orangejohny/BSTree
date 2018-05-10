// example that demonstrates output of nodes
// in particular order

#include <BSTree.hpp>
#include <TUI.hpp>

int main() {
    BSTree::Tree tree{8, 10, 14, 13, 3, 1, 6, 4, 7};
    TUI::print_confirm("BSTree of sequence 8 10 14 13 3 1 6 4 7 was created");

    TUI::print_ln("Direct order:");
    tree.print_nodes(BSTree::Tree::order::direct);
    TUI::print_ln(" ");

    TUI::print_ln("Symmetric order:");
    tree.print_nodes(BSTree::Tree::order::symmetric);
    TUI::print_ln(" ");    

    TUI::print_ln("Reverse order:");
    tree.print_nodes(BSTree::Tree::order::reverse);
    TUI::print_ln(" ");    

    TUI::user_exit();    
}