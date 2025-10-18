#include <iostream>
#include <string>

#include "input_validator.h"

int InputValidator::validate(const int &upper_bound, const int &lower_bound, const std::string &prompt, const std::string &error_message) {
    bool valid_input = false;
    int user_int;

    while (!valid_input) {
        std::cout << prompt; std::cin >> user_int;
        std::cin.ignore(MAX, '\n');

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(MAX, '\n');
            std::cout << error_message << std::endl << std::endl;
        } else if (user_int >= upper_bound || user_int <= lower_bound) {
            std::cout << error_message << std::endl << std::endl;
        } else {
            valid_input = true;
        }
    }

    return user_int;
}

double InputValidator::validate(const double &upper_bound, const double &lower_bound, const std::string &prompt, const std::string &error_message) {
    bool valid_input = false;
    double user_double;

    while (!valid_input) {
        std::cout << prompt; std::cin >> user_double;
        std::cin.ignore(MAX, '\n');

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(MAX, '\n');
            std::cout << error_message << std::endl << std::endl;
        } else if (user_double >= upper_bound || user_double <= lower_bound) {
            std::cout << error_message << std::endl << std::endl;
        } else {
            valid_input = true;
        }
    }

    return user_double;
}

double InputValidator::validate(const std::string &prompt, const std::string &error_message) {
    bool valid_input = false;
    double user_double;

    while (!valid_input) {
        std::cout << prompt; std::cin >> user_double;
        std::cin.ignore(MAX, '\n');

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(MAX, '\n');
            std::cout << error_message << std::endl << std::endl;
        } else {
            valid_input = true;
        }
    }

    return user_double;
}