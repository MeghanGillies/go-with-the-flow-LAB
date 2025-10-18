#include <array>
#include <map>

#include "heat_flow_config.h"

HeatFlow_Config::HeatFlow_Config(const double &initial_temp, const std::map<int, double> &sources_sinks, const double &k) {
    sources_and_sinks = sources_sinks;
    constant_k = k;

    // Chose to make the config build the initial rod instead of passing a rod in
    for (int i = 0; i < 5; i++) {
        try { // Index i is a Source/Sink
            initial_rod.at(i) = sources_and_sinks.at(i);
        } catch (const std::out_of_range) { // Index i is NOT a Source/Sink
            initial_rod.at(i) = initial_temp;
        }
    }
}

std::array<double,5> HeatFlow_Config::get_initial_rod() const {
    return initial_rod;
}

std::map<int, double> HeatFlow_Config::get_source_and_sinks() const {
    return sources_and_sinks;
}

double HeatFlow_Config::get_k() const {
        return constant_k;
}