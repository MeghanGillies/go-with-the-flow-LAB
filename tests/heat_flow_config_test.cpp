#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include <map>
#include <array>
#include "../src/heat_flow_config.h"

TEST_CASE( "All of HeatFlow_Config's getters work as expected" ) {
    std::map<int,double> sources_sinks = {{0, -32.2}, {4, 100}};
    HeatFlow_Config config(20, sources_sinks, 0.1);

    REQUIRE( config.get_initial_rod() == std::array<double, 5> {-32.2, 20, 20, 20, 100} );
    REQUIRE( config.get_source_and_sinks() == sources_sinks );
    REQUIRE( config.get_k() == 0.1 );
}