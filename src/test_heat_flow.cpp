#include <array>

#include "test_heat_flow.h"

Test_HeatFlow::Test_HeatFlow(std::array<double, 5> rod) : current_rod(rod) {};

void Test_HeatFlow::tick() {
    // No Op
}

std::array<double, 5> Test_HeatFlow::get_current_rod(){
    return current_rod;
}