// source file for TUI namespace
#include <TUI.hpp>

auto TUI::change_color(int c) -> void {
    switch (c) {
    case BLUE:
#if defined(__gnu_linux__) || (defined(__APPLE__) && defined(__MACH__))
        std::cout << "\033[34m";
#endif
        break;
    case GREEN:
#if defined(__gnu_linux__) || (defined(__APPLE__) && defined(__MACH__))
        std::cout << "\033[32m";
#endif
        break;
    case DEFAULT:
#if defined(__gnu_linux__) || (defined(__APPLE__) && defined(__MACH__))
        std::cout << "\033[39;49m";
#endif
        break;
    case RED:
#if defined(__gnu_linux__) || (defined(__APPLE__) && defined(__MACH__))
        std::cout << "\033[31m";
#endif
        break;
    case CYAN:
#if defined(__gnu_linux__) || (defined(__APPLE__) && defined(__MACH__))
        std::cout << "\033[36m";
#endif
        break;
    case GRAY:
#if defined(__gnu_linux__) || (defined(__APPLE__) && defined(__MACH__))
        std::cout << "\033[37m";
#endif
    }
}


auto TUI::show_menu() -> void {
    print_ln("Выберите одну из операций:");
    change_color(CYAN);
    std::cout 
    << "1. Вывести дерево на экран\n"
    << "2. Вывести список узлов дерева\n";
    change_color(GRAY);
    std::cout
    << "\ta. Прямой обход\n"
    << "\tb. Поперечный обход\n"
    << "\tc. Обратный обход\n";
    change_color(CYAN);
    std::cout
    << "3. Добавить узел в дерево\n"
    << "4. Удалить узел из дерева\n"
    << "5. Сохранить дерево в файл\n"
    << "6. Загрузить дерево из файла\n"
    << "7. Проверить наличие узла\n"
    << "8. Завершить работу программы\n";
}

auto TUI::sub_menu() -> void {
    print_ln("Выберите порядок обхода:");
    change_color(GRAY);
    std::cout
    << "\ta. Прямой обход\n"
    << "\tb. Поперечный обход\n"
    << "\tc. Обратный обход\n";
}

auto TUI::get_char(std::istream& in) -> char {
    change_color(GREEN);
    return in.get();
}

auto TUI::print_error(const std::string& text) -> void {
    change_color(RED);
    std::cout << text << std::endl;
}


auto TUI::print_f(const std::string& text) -> bool {
    if (text.empty())
        return false;
    change_color(DEFAULT);
    std::cout << text;
    return true;
}


auto TUI::print_ln(const std::string& text) -> bool {
    if (text.empty())
        return false;
    change_color(DEFAULT);
    std::cout << text << std::endl;
    return true;
}


auto TUI::print_confirm(const std::string& text) -> void {
    change_color(GREEN);
    std::cout << text << std::endl;
}


auto TUI::input(std::istringstream& inp) -> int {
    change_color(GREEN);
    int c;
    inp >> c;
    inp.get();

    return c;
}


auto TUI::input(std::istream& inp) -> int {
    change_color(GREEN);
    int c;

    while (!(inp >> c)) {
        print_error("Ошибка ввода!");
        inp.clear();
        while (inp.get() != '\n');
        change_color(GREEN);
    }

    inp.get();

    return c;
}

auto TUI::init_input(int& count, char** argv) -> std::vector<int> {
    if (count == 1) {
        count--;
        return std::vector<int>{};
    }
    
    std::vector<int> values;
    for (int i = 1; i < count; i++) {
        values.push_back(stoi(std::string(*(argv + i))));
    }
    count--;

    return values;
}

auto TUI::str_input(std::istream& inp) -> std::string {
    std::string str;
    change_color(GREEN);
    std::getline(inp, str);

    return str;
}


auto TUI::is_exit() -> int {
    std::string ex;
    print_f("Вы хотите выйти из программы? (y/N) ");
    ex = str_input(std::cin);

    if (ex == "y" || ex == "yes" || ex == "Y" || ex == "Yes" || ex == "YES") {
        return 1;
    }

    if (ex != "n" && ex != "no" && ex != "N" && ex != "No" && ex != "NO") {
        return -1;
    }

    return 0;
}


auto TUI::user_exit() -> void {
    change_color(DEFAULT);
}