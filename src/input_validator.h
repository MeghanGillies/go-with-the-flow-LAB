#pragma once

#include <iostream>
#include <string>

class InputValidator{
private:
    static constexpr std::streamsize MAX{std::numeric_limits<std::streamsize>::max()}; // Max for cin.ignore
public:
    int validate(const int &upper_bound, const int &lower_bound, const std::string &prompt, const std::string &error_message);
    double validate(const double &upper_bound, const double &lower_bound, const std::string &prompt, const std::string &error_message);
    double validate(const std::string &prompt, const std::string &error_message);
};