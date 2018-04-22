


#include "TUI.hpp"
#include "BSTree.hpp"

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "RUS");

    int* values = TUI::init_input(argc, argv);
    if (argc == 0) {
        TUI::print_error("NULL");
    }

    for (int i = 0; i < argc; i++) {
        TUI::print_ln(std::to_string(values[i]));
    }

    return 0;
}