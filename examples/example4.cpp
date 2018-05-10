// example that demonstrates saving the tree to the file
// and loading the tree from it

#include <TUI.hpp>
#include <BSTree.hpp>

int main() {
    BSTree::Tree tree1{8, 10, 14, 13, 3, 1, 6, 4, 7};
    TUI::print_confirm("BSTree of sequence 8 10 14 13 3 1 6 4 7 was created\n");
    tree1.print_tree();

    tree1.save("tree.txt");
    TUI::print_confirm("Tree was saved in tree.txt\n");

    BSTree::Tree tree2;
    tree2.load("tree.txt");
    tree2.print_tree();

    TUI::user_exit();    
}