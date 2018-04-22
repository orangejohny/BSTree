


#include "TUI.hpp"
#include "BSTree.hpp"

using namespace BSTree;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "RUS");

    std::vector<int> values = TUI::init_input(argc, argv);
    Tree tree(values);

    bool exit = false;
    int empty;
    int choice;

    while(true) {
        if (exit) break;
        TUI::show_menu();
        choice = TUI::input(std::cin);
        switch (choice) {
        case 1:
            if (empty = tree.print_tree() == -1) {
                TUI::print_error("Дерево пусто!");
            }
            break;
        case 2:
            TUI::sub_menu();
            switch (TUI::get_char(std::cin)) {
            case 'a':
                TUI::change_color(TUI::GRAY);
                empty = tree.print_nodes(Tree::order::direct);
                break;
            case 'b':
                TUI::change_color(TUI::GRAY);
                empty = tree.print_nodes(Tree::order::symmetric);
                break;
            case 'c':
                TUI::change_color(TUI::GRAY);                
                empty = tree.print_nodes(Tree::order::reverse);
                break;
            default:
                TUI::print_error("Нет такой команды!");
                empty = 1;
            }

            if (empty == -1) {
                TUI::print_error("Дерево пусто!");
            } else if (empty != 1) {
                TUI::print_ln(" ");
            }
            break;
        case 8:
            if (TUI::is_exit() == 1) {
                exit = true;
            }
            break;
        default:
            TUI::print_error("Нет такой команды!");
        }
    }

    TUI::user_exit();

    return 0;
}