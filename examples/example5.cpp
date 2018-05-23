// example that demonstrates if node is in tree

#include <TUI.hpp>
#include <BSTree.hpp>

int main() {
    BSTree::Tree<int> tree{8, 10, 14, 13, 3, 1, 6, 4, 7};
    TUI::print_confirm("BSTree of sequence 8 10 14 13 3 1 6 4 7 was created");

    if (tree.exists(14)) {
        TUI::print_confirm("14 is in tree");
    }

    if (!tree.exists(2)) {
        TUI::print_error("2 is not in tree");
    }

    TUI::user_exit();
}