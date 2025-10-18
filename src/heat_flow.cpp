#include <array>
#include <map>

#include "heat_flow.hpp"
#include "heat_flow_config.h"

HeatFlow::HeatFlow(HeatFlow_Config const &hf_config) :
    config(hf_config),
    sources_and_sinks(hf_config.get_source_and_sinks()),
    initial_rod(hf_config.get_initial_rod()),
    const_k(hf_config.get_k()),
    current_rod(initial_rod)
{}

void HeatFlow::tick() {
    std::array<double, 5> updated_rod;

    for (int i = 0; i < current_rod.size(); ++i) {
        double previous_temp;
        double current_temp = current_rod.at(i);
        double next_temp;

        try { // Index i is a Source/Sink
            updated_rod.at(i) = sources_and_sinks.at(i);

        } catch (const std::out_of_range &) { // Index i is NOT a Source/Sink
            if (i == 0) { // Beginning of Array
                previous_temp = current_temp;
                next_temp = current_rod.at(i + 1);

            } else if (i == current_rod.size() - 1) { //  End of Array
                previous_temp = current_rod.at(i - 1);
                next_temp = current_temp;

            } else { // All other values
                previous_temp = current_rod.at(i - 1);
                next_temp = current_rod.at(i + 1);
            }

            double new_temp = current_temp + (const_k * (next_temp - (2.0 * current_temp) + previous_temp));
            updated_rod.at(i) = new_temp;
        }
    }

    current_rod = updated_rod;
}

std::array<double, 5> HeatFlow::get_current_rod() {
    return current_rod;
}