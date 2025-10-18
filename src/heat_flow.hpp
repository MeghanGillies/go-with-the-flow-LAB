#pragma once

#include <array>
#include <map>

#include "heat_flow_config.h"
#include "heat_flow_base.h"

class HeatFlow : public HeatFlow_Base {
private:
    const HeatFlow_Config config;
    const std::map<int, double> sources_and_sinks;
    const double const_k;
    std::array<double, 5> initial_rod;
    std::array<double, 5> current_rod;

public:
    explicit HeatFlow(HeatFlow_Config const &hf_config);
    void tick() override;
    std::array<double, 5> get_current_rod() override;
};