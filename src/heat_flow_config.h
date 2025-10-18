#pragma once

#include <array>
#include <map>

class HeatFlow_Config {
private:
    std::array<double,5> initial_rod;
    std::map<int, double> sources_and_sinks;
    double constant_k;

public:
    HeatFlow_Config(const double &initial_temp, const std::map<int, double> &sources_sinks, const double &k);

    std::array<double,5> get_initial_rod() const;
    std::map<int, double> get_source_and_sinks() const;
    double get_k() const;
};