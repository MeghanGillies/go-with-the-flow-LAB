#include <string>
#include <array>
#include <sstream>
#include <iomanip>

#include "heat_flow_base.h"
#include "heat_flow_printer.hpp"

HeatFlow_Printer::HeatFlow_Printer(HeatFlow_Base *base_heat_flow) : heat_flow(base_heat_flow) {}

std::string HeatFlow_Printer::generate_header(std::array<double, 5> const &rod) {
    std::stringstream ss;

    for (int i = 0; i < rod.size(); i++) {
        ss << "+--";

        // Convert the double to an int
        // Convert it to a string
        // Use size of the string to get number of dashes
        int num = rod[i];
        std::string num_str = std::to_string(num);

        for (int j = 0; j < num_str.size(); j++) {
            ss << "-";
        }
            ss << "----";
        }

    ss << "+\n";

    return ss.str();
}

std::string HeatFlow_Printer::pretty_print() {
    std::array<double, 5> current_rod = heat_flow->get_current_rod();
    std::stringstream ss;
    std::string header = generate_header(current_rod);

    ss  << header;

    for (int i = 0; i < current_rod.size(); i++) {
        double num = current_rod.at(i);
        ss << "|  " << std::fixed << std::setprecision(1) << num << "  ";
    }

    ss << "|\n" << header;

    return ss.str();
}