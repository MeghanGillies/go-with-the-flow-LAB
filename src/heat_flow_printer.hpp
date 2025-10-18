#pragma once

#include <string>
#include <array>

#include "heat_flow_base.h"

class HeatFlow_Printer {
private:
    HeatFlow_Base *heat_flow;
    std::string generate_header(std::array<double, 5> const &rod);

public:
    HeatFlow_Printer(HeatFlow_Base *base_heat_flow);
    std::string pretty_print();
};