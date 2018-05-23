


#include <TUI.hpp>
#include <BSTree.hpp>

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
            if ((empty = tree.print_tree()) == -1) {
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

        case 3:
            TUI::print_f("Введите значение для нового узла: ");
            if (!tree.insert(TUI::input(std::cin))) {
                TUI::print_error("Узел уже существует в дереве!");
            }
            break;

        case 4:
            TUI::print_f("Введите значение узла: ");
            if (!tree.remove(TUI::input(std::cin))) {
                TUI::print_error("Узел отсутствует!");
            } else {
                TUI::print_confirm("Узел был успешно удалён!");
            }
            break;

        case 5:
            TUI::print_f("Введите путь к файлу: ");
            tree.save(TUI::str_input(std::cin));
            break;

        case 6:
            TUI::print_f("Введите путь к файлу: ");
            if (!tree.load(TUI::str_input(std::cin))) {
                TUI::print_error("Ошибка записи из файла!");
            } else {
                TUI::print_confirm("Дерево было успешно загружено!");
            }
            break;

        case 7:
            TUI::print_f("Введите значение узла: ");
            if (!tree.exists(TUI::input(std::cin))) {
                TUI::print_error("Элемент не найден!");
            } else {
                TUI::print_confirm("Элемент найден!");
            }

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
