// Header file for TUI class

#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>


namespace TUI {
enum { DEFAULT, BLUE, GREEN, RED, CYAN, GRAY };
auto change_color(int) -> void;
auto show_menu() -> void;
auto print_error(const std::string&) -> void;
auto print_f(const std::string&) -> bool;
auto print_ln(const std::string&) -> bool;
auto print_confirm(const std::string&) -> void;
auto input(std::istringstream&) -> int;
auto input(std::istream&) -> int;
auto init_input(int&, char**) -> std::vector<int>;
auto str_input(std::istream&) -> std::string;
auto is_exit() -> int;
auto user_exit() -> void;
};
