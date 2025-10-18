#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/heat_flow.hpp"
#include "../src/heat_flow_config.h"

TEST_CASE( "The temperatures change as expected when calling tick()" ) {
    std::map<int,double> sources_sinks = {{0, 100}};
    HeatFlow_Config config(10, sources_sinks, 0.1);
    HeatFlow heat_flow(config);

    REQUIRE( heat_flow.get_current_rod() == std::array<double, 5> {100, 10, 10, 10, 10} );

    heat_flow.tick();
    REQUIRE( heat_flow.get_current_rod() == std::array<double, 5> {100, 19, 10, 10, 10} );

    heat_flow.tick();
    REQUIRE( heat_flow.get_current_rod() == std::array<double, 5> {100, 26.2, 10.9, 10, 10} );
}
