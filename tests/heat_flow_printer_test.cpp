#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include <array>

#include "../src/heat_flow_printer.hpp"
#include "../src/test_heat_flow.h"

TEST_CASE( "HeatFlow_Printer pretty prints the current rod {1, 2, 3, 4, 5}" ) {
    std::array<double, 5> rod = { 1, 2, 3, 4, 5 };
    Test_HeatFlow test_heat(rod);
    HeatFlow_Printer printer(&test_heat);
    REQUIRE(printer.pretty_print() == "+-------+-------+-------+-------+-------+\n|  1.0  |  2.0  |  3.0  |  4.0  |  5.0  |\n+-------+-------+-------+-------+-------+\n");
}

TEST_CASE( "HeatFlow_Printer pretty prints the current rod {100, 20, 10.77, 10.5, 10}" ) {
    std::array<double, 5> rod = {100, 20, 10.77, 10.5, 10};
    Test_HeatFlow test_heat(rod);
    HeatFlow_Printer printer(&test_heat);
    REQUIRE(printer.pretty_print() == "+---------+--------+--------+--------+--------+\n|  100.0  |  20.0  |  10.8  |  10.5  |  10.0  |\n+---------+--------+--------+--------+--------+\n");
}
