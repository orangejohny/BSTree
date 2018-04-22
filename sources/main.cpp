


#include "TUI.hpp"
#include "BSTree.hpp"

using namespace BSTree;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "RUS");

    std::vector<int> values = TUI::init_input(argc, argv);
    Tree tree(values);

    bool exit = false;
    int choice;

    while(true) {
        if (exit) break;
        TUI::show_menu();
        choice = TUI::input(std::cin);
        switch (choice) {
        case 1:
            if (tree.print_tree() == -1) {
                TUI::print_error("Дерево пусто!");
            }
            break;
        case 8:
            if (TUI::is_exit() == 1) {
                exit = true;
            }
        }
    }

    TUI::user_exit();

    return 0;
}